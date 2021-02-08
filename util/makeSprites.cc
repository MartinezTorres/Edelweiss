////////////////////////////////////////////////////////////////////////
// Build MSX1 palette
//
// Manuel Martinez (salutte@gmail.com)
//
// FLAGS: -std=gnu++14 -g `pkg-config opencv4 --cflags --libs` -Ofast -lpthread -fopenmp -lgomp -Wno-format-nonliteral

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <map>
#include <thread>
#include <chrono>
#include <functional>

using namespace std::chrono_literals;

struct Colorspace {
	
	std::array<float, 256> TsRGB2lin;
	std::array<uint8_t,4096> Tlin2sRGB;

	Colorspace() {
	
		for (size_t i=0; i<256; i++) {
			
			double srgb = (i+0.5)/255.999;
			double lin = 0;
			if (srgb <= 0.0405) {
				lin = srgb/12.92;
			} else {
				lin = std::pow((srgb+0.055)/(1.055),2.4);
			}
			TsRGB2lin[i]=lin;
		}
		
		for (size_t i=0; i<4096; i++) {

			double lin = (i+0.5)/4095.999;
			double srgb = 0;
			if (lin <= 0.0031308) {
				srgb = lin*12.92;
			} else {
				srgb = 1.055*std::pow(lin,1/2.4)-0.055;
			}
			Tlin2sRGB[i]=srgb*255.999999999;
		}
	}

	cv::Vec3f sRGB2Lin(cv::Vec3b a) const {
		
		return {
			TsRGB2lin[a[0]],
			TsRGB2lin[a[1]],
			TsRGB2lin[a[2]]
		};
	}

	cv::Vec3b lin2sRGB(cv::Vec3f a) const {
	
		auto cap = [](float f){	
			int i =  std::round(f*4095.999+0.5);
			return std::min(std::max(i,0),4095); 
		};
		
		return {
			Tlin2sRGB[cap(a[0])],
			Tlin2sRGB[cap(a[1])],
			Tlin2sRGB[cap(a[2])],
		};
	}

	cv::Mat3f sRGB2Lin(cv::Mat3b a) const {

		cv::Mat3f ret(a.rows, a.cols);
		for (int i=0; i<a.rows; i++)
			for (int j=0; j<a.cols; j++) 
				ret(i,j) = sRGB2Lin(a(i,j));

		return ret;
	}

	cv::Mat3b lin2sRGB(cv::Mat3f a) const {

		cv::Mat3b ret(a.rows, a.cols);
		for (int i=0; i<a.rows; i++)
			for (int j=0; j<a.cols; j++) 
				ret(i,j) = lin2sRGB(a(i,j));
				
		return ret;
	}

    static float Y(cv::Vec3b a) {
        
        return a[0]*0.2126 + a[1]*0.7152 + a[2]*0.0722;
    }

    static float perceptualCompare(cv::Vec3b rgb1, cv::Vec3b rgb2) {
        
        const int YR = 19595, YG = 38470, YB = 7471, CB_R = -11059, CB_G = -21709, CB_B = 32767, CR_R = 32767, CR_G = -27439, CR_B = -5329;
		
        cv::Vec3b ycc1, ycc2;
        {
            const int r = rgb1[0], g = rgb1[1], b = rgb1[2];
            ycc1[0] = (r * YR + g * YG + b * YB + 32767) >> 16;
            ycc1[1] = 128 + ((r * CB_R + g * CB_G + b * CB_B + 32768) >> 16);
            ycc1[2] = 128 + ((r * CR_R + g * CR_G + b * CR_B + 32768) >> 16);
        }

        {
            const int r = rgb2[0], g = rgb2[1], b = rgb2[2];
            ycc2[0] = (r * YR + g * YG + b * YB + 32767) >> 16;
            ycc2[1] = 128 + ((r * CB_R + g * CB_G + b * CB_B + 32768) >> 16);
            ycc2[2] = 128 + ((r * CR_R + g * CR_G + b * CR_B + 32768) >> 16);
        }
        
        float Ydiff  = 1.f * std::pow(std::abs(ycc1[0]-ycc2[0]), 1);
        float C1diff = 1.f * std::pow(std::abs(ycc1[1]-ycc2[1]), 1);
        float C2diff = 1.f * std::pow(std::abs(ycc1[2]-ycc2[2]), 1);
        
        return Ydiff + C1diff + C2diff;
    }
    
    static float perceptualDifference(cv::Vec3f rgb1_, cv::Vec3f rgb2_) {
        
        auto f = [](cv::Vec3f c) {
            
            cv::Vec3f yuv;
            yuv[0] =  0.21*c[0]+0.72*c[1]+0.07*c[2];
            yuv[1] = -0.10*c[0]-0.34*c[1]+0.46*c[2];
            yuv[2] =  0.62*c[0]-0.56*c[1]-0.06*c[2];
            return yuv;
        };
        
        cv::Vec3f yuv1 = f(rgb1_), yuv2 = f(rgb2_);
        
        float Ydiff = 1.f * std::pow(std::abs(yuv1[0]-yuv2[0]), 1);
        float Udiff = 1.f * std::pow(std::abs(yuv1[1]-yuv2[1]), 1);
        float Vdiff = 1.f * std::pow(std::abs(yuv1[2]-yuv2[2]), 1);
        
        return Ydiff + Udiff + Vdiff;
    }
};

static Colorspace CS;

struct Tpalette {
    
     std::map<std::string, std::vector<cv::Vec3b>> allColors = { // Note, those are RGB
		{ "HW-MSX", {//https://paulwratt.github.io/programmers-palettes/HW-MSX/HW-MSX-palettes.html
            {   0,   0,   0}, // transparent
            {   1,   1,   1}, // black
            {  62, 184,  73}, // medium green
            { 116, 208, 125}, // light green
            {  89,  85, 224}, // dark blue
            { 128, 118, 241}, // light blue
            { 185,  94,  81}, // dark red
            { 101, 219, 239}, // cyan
            { 219, 101,  89}, // medium red
            { 255, 137, 125}, // light red
            { 204, 195,  94}, // dark yellow
            { 222, 208, 135}, // light yellow
            {  58, 162,  65}, // dark green
            { 183, 102, 181}, // magenta
            { 204, 204, 204}, // gray
            { 255, 255, 255}  // white
        } }, 
            
        { "Toshiba Palette", {
            {   0,   0,   0 }, // transparent,
            {   0,   0,   0 }, // black,
            { 102, 204, 102 }, // medium green,
            { 136, 238, 136 }, // light green,
            {  68,  68, 221 }, // dark blue,
            { 119, 119, 255 }, // light blue,
            { 187,  85,  85 }, // dark red,
            { 119, 221, 221 }, // cyan,
            { 221, 102, 102 }, // medium red,
            { 255, 119, 119 }, // light red,
            { 204, 204,  85 }, // dark yellow,
            { 238, 238, 136 }, // light yellow,
            {  85, 170,  85 }, // dark green,
            { 187,  85, 187 }, // magenta,
            { 204, 204, 204 }, // gray,
            { 238, 238, 238 }  // white,
        } },
        
        { "TMS9918A (NTSC)", {
            {   0,   0,   0 }, // transparent,
            {   0,   0,   0 }, // black,
            {  71, 183,  62 }, // medium green,
            { 124, 208, 108 }, // light green,
            {  99, 91,  169 }, // dark blue,
            { 127, 113, 255 }, // light blue,
            { 183, 98,   73 }, // dark red,
            {  92, 199, 239 }, // cyan,
            { 217, 107,  72 }, // medium red,
            { 253, 142, 108 }, // light red,
            { 195, 206,  66 }, // dark yellow,
            { 211, 219, 117 }, // light yellow,
            {  61, 160,  47 }, // dark green,
            { 183,  99, 199 }, // magenta,
            { 205, 205, 205 }, // gray,
            { 255, 255, 255 }  // white,
        } },
        
        { "TMS9929A (PAL)", {
            {   0,   0,   0 }, // transparent,
            {   0,   0,   0 }, // black,
            {  81, 202,  92 }, // medium green,
            { 133, 223, 141 }, // light green,
            { 108, 103, 240 }, // dark blue,
            { 146, 137, 255 }, // light blue,
            { 213, 100, 113 }, // dark red,
            { 102, 219, 239 }, // cyan,
            { 231, 118, 131 }, // medium red,
            { 255, 152, 164 }, // light red,
            { 215, 207,  97 }, // dark yellow,
            { 230, 222, 112 }, // light yellow,
            {  74, 177,  81 }, // dark green,
            { 200, 121, 200 }, // magenta,
            { 205, 205, 205 }, // gray,
            { 255, 255, 255 }  // white,
        } },
        
        { "TMS9929A (PAL, alternate GAMMA)", {
            {   0,   0,   0 }, // transparent,
            {   0,   0,   0 }, // black,
            {  72, 178,  81 }, // medium green,
            { 117, 196, 125 }, // light green,
            {  95,  91, 212 }, // dark blue,
            { 129, 121, 224 }, // light blue,
            { 187,  89,  99 }, // dark red,
            {  90, 193, 210 }, // cyan,
            { 203, 104, 115 }, // medium red,
            { 224, 134, 145 }, // light red,
            { 189, 182,  86 }, // dark yellow,
            { 203, 196,  99 }, // light yellow,
            {  66, 156,  72 }, // dark green,
            { 176, 108, 175 }, // magenta,
            { 180, 180, 180 }, // gray,
            { 255, 255, 255 }  // white,
        } }
	};
    
    const std::string name;

    typedef std::pair<std::array<cv::Vec3b, 4>, std::array<size_t, 2>> Palette4;
	std::vector<Palette4> allPalettes;
    
    cv::Mat3b colorMatrix;
	
//	Tpalette(std::string name = "HW-MSX") {
	Tpalette(std::string name = "TMS9918A (NTSC)") : name(name) {
        
        auto colors = allColors.find(name)->second;

        colorMatrix = cv::Mat3b(14,14);
  		for (size_t j=1; j<colors.size(); j++)
            for (size_t k=1; k<colors.size(); k++)
                colorMatrix((j>8?j-2:j-1),(k>8?k-2:k-1)) = CS.lin2sRGB((CS.sRGB2Lin(colors[j]) + CS.sRGB2Lin(colors[k]))*0.5);
        
        
        std::vector<Palette4> tentativePalettes;        
		//for (size_t i=1; i<colors.size(); i++) { // I is the background color, which is common to both tiles.
        size_t i = 1; { //On a better though, let's fix the background to black so we can perfilate everything.
			for (size_t j=1; j<colors.size(); j++) { // J is the first foreground color
                if (j==i) continue;
                if (j==8) continue;
                for (size_t k=j; k<colors.size(); k++) { // K is the second foreground color
                    if (k==i) continue;
                    if (k==8) continue;
                    
                    Palette4 p4 = { {
                        colors[i],
                        CS.lin2sRGB((CS.sRGB2Lin(colors[i]) + CS.sRGB2Lin(colors[j]))*0.5),
                        CS.lin2sRGB((CS.sRGB2Lin(colors[i]) + CS.sRGB2Lin(colors[k]))*0.5),
                        CS.lin2sRGB((CS.sRGB2Lin(colors[j]) + CS.sRGB2Lin(colors[k]))*0.5),
                    }, {j, k} };
                        
                    
                    if (j==k) {
                    //    allPalettes.push_back(p4);
                    } else {
                        tentativePalettes.push_back(p4);
                    }
                }
            }
		}
        
        std::random_shuffle(tentativePalettes.begin(), tentativePalettes.end());
                
        for (auto &tp : tentativePalettes) {
            auto &t = tp.first;
            float minD = 1e10;
            for (auto &pp : allPalettes) {
                auto &p = pp.first;
                float d = 0.f;
                auto perceptualCompare = Colorspace::perceptualCompare;
                d += std::min(std::min(std::min(perceptualCompare(t[0],p[0]), perceptualCompare(t[0],p[1])), perceptualCompare(t[0],p[2])), perceptualCompare(t[0],p[3]));
                d += std::min(std::min(std::min(perceptualCompare(t[1],p[0]), perceptualCompare(t[1],p[1])), perceptualCompare(t[1],p[2])), perceptualCompare(t[1],p[3]));
                d += std::min(std::min(std::min(perceptualCompare(t[2],p[0]), perceptualCompare(t[2],p[1])), perceptualCompare(t[2],p[2])), perceptualCompare(t[2],p[3]));
                d += std::min(std::min(std::min(perceptualCompare(t[3],p[0]), perceptualCompare(t[3],p[1])), perceptualCompare(t[3],p[2])), perceptualCompare(t[3],p[3]));
                minD = std::min(minD, d);
            }
            //std::cout << minD << std::endl;
            if (minD>75)
                allPalettes.push_back(tp);
        }
        
        std::sort(allPalettes.begin(), allPalettes.end(), [](const Palette4 &a, const Palette4 &b){
            if (a.second[0]!=b.second[0]) return a.second[0]<b.second[0];
            return a.second[1]<b.second[1];
        });
	}
    
    struct Tile { std::array<uint8_t,8> pattern, color; };
    std::array<Tile ,2> findBestPatterns(cv::Mat3b bgr, bool forceDebug=false) const {
        
        cv::Mat3b rgb = bgr.clone();
        for (auto &c : rgb) std::swap(c[0], c[2]);
    
        cv::Mat3b debugImg(8,32);
        rgb.copyTo(debugImg(cv::Rect(24,0,8,8)));
        bool showDebug = false;

        std::array<Tile ,2> ret;
        for (size_t line = 0; line<8; line++) {
            uint8_t colorA=0, colorB=0;
            double best = 1e10;
            for (int i=1; i<colorMatrix.rows; i++) {
                for (int j=i; j<colorMatrix.cols; j++) {
                    double cost = 0;
                    for (size_t k=0; k<8; k++) {
                        cost += pow(
                                std::min( Colorspace::perceptualCompare(colorMatrix(0,0), rgb(line,k)),
                                std::min( Colorspace::perceptualCompare(colorMatrix(0,j), rgb(line,k)),
                                std::min( Colorspace::perceptualCompare(colorMatrix(i,0), rgb(line,k)),
                                    1.01f*Colorspace::perceptualCompare(colorMatrix(i,j), rgb(line,k))))),2);
                    }
                    if (i != j) cost += 1;
                    if (cost<best) {
                        best = cost;
                        colorA = i;
                        colorB = j;
                        std::cerr << int(colorA) << " " << int(colorB) << " " << cost << std::endl;
                    }
                }
            }
            if (line%2) std::swap(colorA, colorB);
            std::cerr << int(colorA) << " " << int(colorB) << " " << std::endl;
            
                
            ret[0].pattern[line] = 0;
            ret[1].pattern[line] = 0;
            for (size_t k=0; k<8; k++) {
                
                uint pA = 0, pB = 0;
                double best = Colorspace::perceptualCompare(colorMatrix(0,0), rgb(line,k));
                double c;

                if ( (c = Colorspace::perceptualCompare(colorMatrix(colorA,0), rgb(line,k))) < best) {
                    best = c; pA = 1; pB = 0;
                }
                
                if ( (c = Colorspace::perceptualCompare(colorMatrix(0,colorB), rgb(line,k)))*1.01 < best) {
                    best = c; pA = 0; pB = 1;
                }

                if ( (c = Colorspace::perceptualCompare(colorMatrix(colorA,colorB), rgb(line,k)))*1.02 < best) {
                    best = c; pA = 1; pB = 1;
                }
                if (colorA==colorB and (k+line)%2 == 1)
                    std::swap(pA, pB);
                
                ret[0].pattern[line] = (ret[0].pattern[line]<<1) + pA;
                ret[1].pattern[line] = (ret[1].pattern[line]<<1) + pB;
                
                debugImg(line,0*8+k) = colorMatrix(pA*colorA,0);
                debugImg(line,1*8+k) = colorMatrix(0,pB*colorB);
                debugImg(line,2*8+k) = colorMatrix(pA*colorA,pB*colorB);
            }
            ret[0].color[line] = (colorA>6?colorA+2:colorA+1)<<4;
            ret[1].color[line] = (colorB>6?colorB+2:colorB+1)<<4;

            if (best > 50) {
                std::cerr << line << ": " << best << std::endl;
                showDebug = true;
            }
        }

        if (showDebug or forceDebug) {
            cv::Mat3b debug2;
            cv::resize(debugImg,debug2,cv::Size(0,0), 10, 10,cv::INTER_NEAREST);
            

            for (auto &c : debug2) std::swap(c[0], c[2]);
            
            cv::imshow("debug", debug2);
            cv::waitKey(10);
            if (forceDebug) cv::waitKey(0);
        }
        return ret;
    }
    

    cv::Mat1b paletizeSprite(cv::Mat3b inBGR) {

        cv::Mat3b in = inBGR.clone();
        for (auto &p: in) std::swap(p[0],p[2]);
        
        auto colors = allColors.find(name)->second;        
        colors[0] = cv::Vec3b(255,255,0); // transparent is labeled as strong yellow.
        
        cv::Mat1b out(in.rows, in.cols);
        for (int i=0; i<in.rows; i++) {
            for (int j=0; j<in.cols; j++) {

                float minD = 1e10;
                for (uint k=0; k<colors.size(); k++) {
                    float d = Colorspace::perceptualCompare(colors[k],in(i,j));
                    if (d < minD) {
                        minD = d;
                        out(i,j) = k;
                    }
                }
                if (minD>40) std::cerr << "minD elevated: " << minD << std::endl;
            }
        }
        return out;        
    }

};


int main(int argc, const char *argv[]) {

    Tpalette P; 
    char msg[100];


    // a map has:
    //  original map, and any number of altered maps. Traversability is independent of mapping (as are objects).
    //  animations will be handled at the tile level.
    
    if (argc<3) { std::cerr << "usage: makeSprites name spirteFile" << std::endl; exit(-1); }
    
    struct Sprite16 {
        std::array<uint16_t,16> pattern;
        uint8_t color;
    };
    
    struct FullSprite16 {
        cv::Mat3b img;
        cv::Mat3b rgb;
        std::array<uint16_t,16> blackMask;
        std::vector<Sprite16> colorSprites;
    };


    std::map<int,std::map<int, FullSprite16>> sprites;
    {
        cv::Mat3b img = cv::imread(argv[2]);
        
        for (int i=0; i+15<img.rows; i+=16) {
            for (int j=0; j+15<img.cols; j+=16) {
                
                cv::Mat1i colorHistogram(P.colorMatrix.rows, 1, 0);
                std::cout << P.colorMatrix.rows << " " << P.colorMatrix.cols << std::endl;
                
                
                FullSprite16 sprite;
                sprite.img = img(cv::Rect(j,i,16,16)).clone();
                
                cv::Mat3b rgb = sprite.img.clone();
                for (auto &p : rgb) std::swap(p[0],p[2]);
                sprite.rgb = rgb;
                
                std::map<int,Sprite16> colorSprites;
                for (int ii=0; ii<14; ii++) colorSprites[ii].color = (ii>6?ii+2:ii+1);
                                
                bool blackMaskFound = false;
                for (int ii=0; ii<16; ii++) {
                    sprite.blackMask[ii]=0;
                    for (auto &cs : colorSprites) cs.second.pattern[ii]=0;
                    
                    for (int jj=0; jj<16; jj++) {
                        sprite.blackMask[ii] <<= 1;
                        for (auto &cs : colorSprites) cs.second.pattern[ii]<<=1;                    
                    
                        float d = Colorspace::perceptualCompare(sprite.rgb(ii,jj),cv::Vec3f(255,255,0));
                        //std::cout << d << std::endl;
                        if (d>10) {
                            sprite.blackMask[ii] |= 1;
                            blackMaskFound = true;

                            {
                                int besti=0, bestj=0;
                                float bestScore = 1e10;
                                for (int ki=0; ki<P.colorMatrix.rows; ki++) {
                                    for (int kj=0; kj<=ki; kj++) {
                                        float s = Colorspace::perceptualCompare(sprite.rgb(ii,jj),P.colorMatrix(ki,kj));
                                        if (s<bestScore) {
                                            bestScore = s;
                                            besti = ki;
                                            bestj = kj;
                                        }
                                    }
                                }
                                colorSprites[besti].pattern[ii] |= 1;                    
                                colorSprites[bestj].pattern[ii] |= 1;
                                
                                colorHistogram(besti)++;
                                colorHistogram(bestj)++;
                            }
                        }
                    }
                }
                if (blackMaskFound) {
                    
                    std::cout << "Found " << sprites.size() << " sprites." << std::endl;
                    for (int i=1; i<colorHistogram.rows; i++) {
                        if (colorHistogram(i)>0) {
                            
                            sprite.colorSprites.push_back(colorSprites[i]);
                            std::cout << "Requires color: " << i << " (" << colorHistogram(i) << " pixels)" << std::endl;
                        }
                    }
                    
                    if (sprite.colorSprites.size()!=2) { 
						std::cerr << "Not two colors needed" << std::endl; 
                        sprite.colorSprites.push_back(sprite.colorSprites.back());
						//exit(-1); 			
					}
                    
                    sprites[i/16][j/16] = sprite;
                }
            }
        }
    }
    
    

    std::string SPRITE_NAME = argv[1];
    
    // Prepare external header
    {
        std::ofstream header(SPRITE_NAME+".h");
        header << "#pragma once" << std::endl;
        header << "#include <sprites/common.h>" << std::endl;
        for (auto &sr : sprites) {
            for (auto &sc : sr.second) {
                header << "extern const TSpriteInterlaced " << SPRITE_NAME << "_" << sr.first << "_" << sc.first << ";" << std::endl;
            }
        }

    }

    // Spawn Implementation
    {
        std::ofstream src(SPRITE_NAME+".c");
        src << "#include <sprites/common.h>" << std::endl;
        for (auto &sr : sprites) {
            for (auto &sc : sr.second) {
                src << "const TSpriteInterlaced " << SPRITE_NAME << "_" << sr.first << "_" << sc.first << " = {" << std::endl;
                
                src << "{";
                for (int i=0; i<8; i++) {
                    src << " {";
                    for (auto m : sc.second.blackMask) { sprintf(msg,"0x%02X,", (((int(m)<<8)>>i)>>16) & 0xFF); src << msg; } src << std::endl << "  ";
                    for (auto m : sc.second.blackMask) { sprintf(msg,"0x%02X,", (((int(m)<<8)>>i)>>8 ) & 0xFF); src << msg; } src << std::endl << "  ";
                    for (auto m : sc.second.blackMask) { sprintf(msg,"0x%02X,", (((int(m)<<8)>>i)    ) & 0xFF); src << msg; } src << "}, " << std::endl;
                }
                src << "}, "  << std::endl;

                src << "{";
                for (auto m : sc.second.colorSprites[0].pattern) { sprintf(msg,"0x%02X,", m>>8); src << msg; } src << std::endl << " ";
                for (auto m : sc.second.colorSprites[0].pattern) { sprintf(msg,"0x%02X,", m&0xFF); src << msg; } src << "}, " << std::endl;
                src << "{";
                for (auto m : sc.second.colorSprites[1].pattern) { sprintf(msg,"0x%02X,", m>>8); src << msg; } src << std::endl << " ";
                for (auto m : sc.second.colorSprites[1].pattern) { sprintf(msg,"0x%02X,", m&0xFF); src << msg; } src << "}, " << std::endl;
                src << int(sc.second.colorSprites[0].color) << ", " << int(sc.second.colorSprites[1].color) << "};" << std::endl;
            }
        }
    }
}

