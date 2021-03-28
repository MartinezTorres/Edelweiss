////////////////////////////////////////////////////////////////////////
// Build MSX1 palette
//
// Manuel Martinez (salutte@gmail.com)
//
// FLAGS: -std=gnu++14 -g `pkg-config opencv4 --cflags --libs` -O0 -lpthread -fopenmp -lgomp -Wno-format-nonliteral

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

#include "uSnippets/sXML.hpp"

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
    
    
    static float luminance(cv::Vec3f c) {
                
        return 0.21*c[0]+0.72*c[1]+0.07*c[2];
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

    typedef std::pair<std::array<cv::Vec3b, 4>, std::array<size_t, 2>> Palette4;
	std::vector<Palette4> allPalettes;
    
    cv::Mat3b colorMatrix;
	
//	Tpalette(std::string name = "HW-MSX") {
	Tpalette(std::string name = "TMS9918A (NTSC)") {
        
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
                        //std::cerr << int(colorA) << " " << int(colorB) << " " << cost << std::endl;
                    }
                }
            }
            if (Colorspace::luminance(colorMatrix(0,colorA)) < Colorspace::luminance(colorMatrix(0,colorB))) std::swap(colorA, colorB);
            if (line%2) std::swap(colorA, colorB);
            //std::cerr << int(colorA) << " " << int(colorB) << " " << std::endl;
            
                
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
                //std::cerr << line << ": " << best << std::endl;
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
    
};


int main(int argc, const char *argv[]) {

    Tpalette P; 
    char msg[100];


    // a map has:
    //  original map, and any number of altered maps. Traversability is independent of mapping (as are objects).
    //  animations will be handled at the tile level.
    
    if (argc<4) { std::cerr << "usage: makeMap name animatedTiles tileMap tileFlags map0 {map1} {map2} {map3}" << std::endl; exit(-1); }

    // Load image corresponding to animated tiles
    struct Tile8 {
        cv::Mat3b img;
        std::array<Tpalette::Tile ,2> msx1_interlaced;
        size_t count;
    };
    std::vector<Tile8> tiles8L, tiles8R;
    {
        Tile8 black;
        black.img = cv::Mat3b(8,8,cv::Vec3b(0,0,0));
        black.msx1_interlaced = P.findBestPatterns(black.img, false);
        black.count = 1;
        
        tiles8L.push_back(black);
        tiles8R.push_back(black);
    }
        
    
    
    std::vector<std::vector<Tile8>> animatedTiles;
    {
        cv::Mat3b img = cv::imread(argv[2]);
        if (img.rows % 8) { std::cerr << "animated tiles not multiple of 8" << std::endl; exit(-1); }
        if (img.cols != 32) { std::cerr << "animated tiles not 4 tiles wide" << std::endl; exit(-1); }        

        for (int i=0; i+7<img.rows; i+=8) {
            std::vector<Tile8> at;
            for (int j=0; j+7<img.cols; j+=8) {

                Tile8 tile8;
                tile8.img = img(cv::Rect(j,i,8,8)).clone();
                tile8.msx1_interlaced = P.findBestPatterns(tile8.img, false);
                tile8.count = 1;
                at.push_back(tile8);
            }
            animatedTiles.push_back(at);
            tiles8L.push_back(at.front());
            tiles8R.push_back(at.front());
        }
    }

    
    // Process all Maps, find all unique 16x16 tiles.
    struct Map {
        cv::Mat3b img;
        cv::Mat3b flags;
        cv::Mat1b map16;
    };    
    std::vector<Map> maps;
    
    struct Tile16 {
		cv::Point source;
        cv::Mat3b img;
        cv::Mat3b flags;
        cv::Matx< int, 2, 2 > idx;
        size_t count;
    };
    std::vector<Tile16> tiles16;

	cv::Mat1b tileMap_idx;
    
    {
		cv::Mat3b tileMap = cv::imread(argv[3]);
		cv::Mat3b tileFlags = cv::imread(argv[4]);
		
		tileMap_idx = cv::Mat1b(tileMap.rows/16, tileMap.cols/16, uint8_t(0));
		
        for (int i=5; i<argc; i++) {
            
            maps.push_back(Map());
            Map &map = maps.back();
            
            {
				uSnippets::sXML map_xml;
				std::ifstream iff(argv[i]);
				
				std::string s;
				
				iff >> s >> s >> s >> map_xml;
				
				size_t width = map_xml("layer")["width"];
				size_t height = map_xml("layer")["height"];
				
				map.img = cv::Mat3b(height*16, width*16);
				
				std::string data = map_xml("layer")("data")()[0].tag; 
				for (auto &c : data) if (c==',') c=' ';
				std::istringstream iss(data);
				
				std::cerr << tileMap.rows << " " << tileMap.cols << std::endl;
				
				for (int ii = 0; ii<height; ii++) {
					for (int jj = 0; jj<width; jj++) {
						int idx;
						iss >> idx;
						idx--;
						//if (idx<0) idx = 0;
						int h = idx / (tileMap.cols/16);
						int w = idx % (tileMap.cols/16);
					
						std::cerr << h*16 << " " << w*16 << std::endl;
						
						tileMap(cv::Rect(w*16,h*16,16,16)).copyTo(map.img(cv::Rect(jj*16, ii*16, 16, 16)));
						
					}
				}
				cv::imshow("map", map.img);
				cv::waitKey(0);
			}
            
            
            if (maps.size() and map.img.size() != maps.front().img.size()) { std::cerr << "inconsistnt map size" << std::endl; exit(-1); }
            if (map.img.rows % 16) { std::cerr << "map size not multiple of 16" << std::endl; exit(-1); }
            if (map.img.cols % 16) { std::cerr << "map size not multiple of 16" << std::endl; exit(-1); }

            map.map16 = cv::Mat1b(map.img.rows/16, map.img.cols/16);
            for (int i=0; i+15<map.img.rows; i+=16) {
                for (int j=0; j+15<map.img.cols; j+=16) {
                    cv::Mat3b tile = map.img(cv::Rect(j,i,16,16));
                    
                    bool found = false;
                    for (uint k=0; not found and k<tiles16.size(); k++) {
                        auto &t = tiles16[k].img;
                        double n = cv::norm(tile-t) + cv::norm(t-tile);
                        //if (n<1) {
						if (n<1) {
                            
                            tiles16[k].img.copyTo(tile);
                            tiles16[k].count++;
                            map.map16(i/16,j/16) = k;
                            found = true;
                        }
                    }
                    if (not found) {
                        map.map16(i/16,j/16) = tiles16.size();
                        Tile16 tile16;
                        tile16.img = tile.clone();
                        tile16.count = 1;
                        
                        tile16.flags = cv::Mat3b(16,16,cv::Vec3b(0,0,0));

						for (int ii=0; ii+15<tileMap.rows; ii+=16) {
							for (int jj=0; jj+15<tileMap.cols; jj+=16) {
								cv::Mat3b t = tileMap(cv::Rect(jj,ii,16,16));
								cv::Mat3b f = tileFlags(cv::Rect(jj,ii,16,16));
								double n = cv::norm(tile-t) + cv::norm(t-tile);
								if (n<1) {
									tile16.source = { ii, jj };
									tile16.flags = cv::max(tile16.flags, f.clone());
								}
							}
						}
                        tiles16.push_back(tile16);
                    }
                }
            }

            map.flags = map.img.clone();
            for (int i=0; i+15<map.img.rows; i+=16) {
                for (int j=0; j+15<map.img.cols; j+=16) {

					int k = map.map16(i/16,j/16);

					tiles16[k].flags.copyTo(map.flags(cv::Rect(j,i,16,16)));
                }
            }

            
            cv::imwrite("flags.png", map.flags);
        }
        std::cout << "Found " << tiles16.size() << " unique 16x16 tiles." << std::endl;
        if (tiles16.size()>256) { std::cerr << "Too many unique 16x16 tiles." << std::endl; exit(-1); }

		for (int i=0; i+15<tileMap.rows; i+=16) {
			for (int j=0; j+15<tileMap.cols; j+=16) {
				cv::Mat3b tile = tileMap(cv::Rect(j,i,16,16));
				
				bool found = false;
				for (uint k=0; not found and k<tiles16.size(); k++) {
					auto &t = tiles16[k].img;
					double n = cv::norm(tile-t) + cv::norm(t-tile);
					if (n<1) {
						tileMap_idx(i/16,j/16) = k;
						found = true;
					}
				}
				
				//cv::Mat3b tileBig; cv::resize(tile, tileBig, cv::Size(), 8, 8, cv::INTER_NEAREST);
				//cv::imshow("img", tileBig);
				//std::cerr << int(tileMap_idx(i/16,j/16)) << "\t" << tiles16[tileMap_idx(i/16,j/16)].count << std::endl;
				//cv::waitKey(0);
				
			}
		}




    }

    // Find all unique 8x8 tiles.
    {
        for (auto &tile16 : tiles16) {

            for (int i=0; i+7<tile16.img.rows; i+=8) {
                for (int j=0; j+7<tile16.img.cols; j+=8) {
                    
                    std::vector<Tile8> &tiles8 = (j==0?tiles8L:tiles8R);
                    
                    cv::Mat3b tile = tile16.img(cv::Rect(j,i,8,8));
                    
                    bool found = false;
                    for (uint k=0; not found and k<tiles8.size(); k++) {
                        auto &t = tiles8[k].img;
                        double n = cv::norm(tile-t) + cv::norm(t-tile);
                        if (n<1) {
                            
                            tiles8[k].img.copyTo(tile);
                            tiles8[k].count++;
                            tile16.idx(i/8,j/8) = k;
                            found = true;
                        }
                    }
                    if (not found) {
                        tile16.idx(i/8,j/8) = tiles8.size();
                        Tile8 tile8;
                        tile8.img = tile.clone();
                        tile8.msx1_interlaced = P.findBestPatterns(tile8.img);
                        tile8.count = 1;
                        tiles8.push_back(tile8);
                    }
                }
            }
        }
        std::cout << "Found " << tiles8L.size() << " unique 8x8 tiles on even columns." << std::endl;
        std::cout << "Found " << tiles8R.size() << " unique 8x8 tiles on odd columns." << std::endl;
        if (tiles8L.size()>256) { std::cerr << "Too many unique 8x8 tiles on even columns." << std::endl; exit(-1); }        
        if (tiles8R.size()>256) { std::cerr << "Too many unique 8x8 tiles on odd columns." << std::endl; exit(-1); }        
    }

    // Check that no more than 96 tiles are in use simultaneously within a 32 x 8 window
    {
        int score = 0;
        cv::Mat1d histMap(2*maps.front().map16.rows, 2*maps.front().map16.cols, 0.);
        int t8Rows = 2*maps.front().map16.rows;
        int t8Cols = 2*maps.front().map16.cols;
        static constexpr const struct { int width = 32+1, height = 8+1; } window;
        for (int i=0; i+window.height-1 < t8Rows; i++) {
            for (int j=0; j+window.width-1 < t8Cols; j++) {

                std::map<std::pair<size_t,size_t>, int> uniqueTiles;
                for (size_t m = 0; m<maps.size(); m++) {
                    for (int ii=0; ii<window.height; ii++) {
                        for (int jj=0; jj<window.width; jj++) {
                            int tile16Idx = maps[m].map16((i+ii)/2,(j+jj)/2);
                            auto &tile16 = tiles16[tile16Idx];
                            size_t tile8Idx = tile16.idx((i+ii)%2,(j+jj)%2);

                            if (tile8Idx<animatedTiles.size()) continue;
                            uniqueTiles[{jj%2,tile8Idx}]++;
                        }
                    }
                }
                if (uniqueTiles.size()>96) { std::cerr << uniqueTiles.size() << " unique 8x8 tiles at: (" << i << ", " << j << ")" << std::endl; }
//                if (uniqueTiles.size()>96) { std::cerr << "Too many unique 8x8 tiles at: (" << i << ", " << j << ")" << std::endl; }
//                if (uniqueTiles.size()>112) { std::cerr << "Too many unique 8x8 tiles at: (" << i << ", " << j << ")" << std::endl; exit(-1); }

                score = std::max(score,int(uniqueTiles.size()));
                for (int ii=0; ii<window.height; ii++) {
                    for (int jj=0; jj<window.width; jj++) {
                        histMap(i+ii,j+jj) = std::max(histMap(i+ii,j+jj), double(uniqueTiles.size()));
                    }
                }
            }
        }
        
        if (score>64) {

            cv::Mat3b heatMap(histMap.rows, histMap.cols, cv::Vec3b(0,0,0));
            for (int i=0; i<histMap.rows; i++) {
                for (int j=0; j<histMap.cols; j++) {
                    if (histMap(i,j)<64) {
                        heatMap(i,j)=cv::Vec3b(0,255,0);
                    } else if (histMap(i,j)<96) {
                        heatMap(i,j)=cv::Vec3b(0,255,255);
                    } else if (histMap(i,j)<112) {
                        heatMap(i,j)=cv::Vec3b(0,128,255);                        
                    } else {
                        heatMap(i,j)=cv::Vec3b(0,0,255);
                    }
                }
            }
            cv::resize(heatMap, heatMap, cv::Size(), 8, 8, cv::INTER_LINEAR);
            cv::imwrite("heatmap.png", heatMap);
            cv::imshow("heatmap.png", heatMap);
            cv::waitKey(0);
        }
    }
            


    std::string MAP_NAME = argv[1];
    uint NUM_ANIMATED_TILES = animatedTiles.size();
    uint NUM_ANIMATED_FRAMES = (animatedTiles.size()?animatedTiles.front().size():0);
    uint NUM_MAPS = maps.size();
    uint MAP16_Y = maps.front().map16.rows;
    uint MAP16_X = maps.front().map16.cols;
    
    // Prepare external header
    {
        std::ofstream header(MAP_NAME+".h");
        header << "#pragma once" << std::endl;
        header << "#define MAP_NAME " << MAP_NAME << std::endl;
        header << "#include <map_interface.h>" << std::endl;
        header << "#undef MAP_NAME" << std::endl;
        
        header << "#define " << MAP_NAME << "_TILEMAP(x,y) (";
        for (int i=0; i<tileMap_idx.rows; i++) {
			for (int j=0; j<tileMap_idx.cols; j++) {
				header << "x=="<<j<<"&&"<<"y=="<<i<<"?"<<int(tileMap_idx(i,j))<<":";
			}
		}
        header << "0)";
    }

    // Spawn Implementation
    {
        std::ofstream src(MAP_NAME+".c");
        src << "#include <common.h>" << std::endl;
        src << "#define MAP_NAME " << MAP_NAME << std::endl;
        src << "#include <map_interface.h>" << std::endl;
        src << "#define NUM_ANIMATED_TILES " << NUM_ANIMATED_TILES << std::endl;
        src << "#define NUM_ANIMATED_FRAMES " << NUM_ANIMATED_FRAMES << std::endl;        
        src << "#define NUM_MAPS " << NUM_MAPS << std::endl;
        src << "#define MAP16_Y " << MAP16_Y << std::endl;
        src << "#define MAP16_X " << MAP16_X << std::endl;

        src << "#define MAP_ANIMATED " << (MAP_NAME + std::string("_animated")) << std::endl;
        src << "USING_MODULE(" << (MAP_NAME + std::string("_animated")) << ", PAGE_C);" << std::endl;
        src << "extern const uint8_t " << (MAP_NAME + std::string("_animated")) << "[" << NUM_ANIMATED_FRAMES << "][2][" << NUM_ANIMATED_TILES * 16 << "];" << std::endl;

        src << "#define MAP_MAP16 " << (MAP_NAME + "_map" + char('0'+0) + "_map16") << std::endl;
        for (size_t m=0; m<maps.size(); m++) {
            src << "#define MAP" <<  char('0'+m) << "_MAP16 " << (MAP_NAME + "_map" + char('0'+m) + "_map16") << std::endl;
            src << "USING_MODULE("  << (MAP_NAME + "_map" + char('0'+m) + "_map16") << ", PAGE_D);" << std::endl;
            src << "extern const uint8_t " << (MAP_NAME + "_map" + char('0'+m) + "_map16") << "[" << MAP16_Y << "]["<< MAP16_X << "];" << std::endl;
        }
        for (size_t m=maps.size(); m<10; m++) {
            src << "#define MAP" <<  char('0'+m) << "_MAP16 " << (MAP_NAME + "_map" + char('0') + "_map16") << std::endl;
		}


        src << "#define MAP_TILES16 " << (MAP_NAME + "_tiles16") << std::endl;
        src << "USING_MODULE("  << (MAP_NAME + "_tiles16") << ", PAGE_C);" << std::endl;
        src << "extern const uint8_t " << (MAP_NAME + "_tiles16") << "[256][2][2];" << std::endl;

		for (int i=0; i<16; i++) {
			src << "#define MAP_TILES16_FLAGS_" << i << " " << MAP_NAME << "_tiles16_flags_" << i << std::endl;
			src << "USING_MODULE("  << MAP_NAME << "_tiles16_flags_" << i << ", PAGE_C);" << std::endl;
			src << "extern const uint8_t " << MAP_NAME << "_tiles16_flags_" << i << "[16][256];" << std::endl;			
		}

        src << "#define MAP_TILES16_TRAV " << (MAP_NAME + "_tiles16_flag_traversability") << std::endl;
        src << "USING_MODULE("  << (MAP_NAME + "_tiles16_flag_traversability") << ", PAGE_C);" << std::endl;
        src << "extern const uint8_t " << (MAP_NAME + "_tiles16_flag_traversability") << "[256][2][2][8];" << std::endl;

        src << "#define MAP_TILES16_TRIG " << (MAP_NAME + "_tiles16_flag_trigger") << std::endl;
        src << "USING_MODULE("  << (MAP_NAME + "_tiles16_flag_trigger") << ", PAGE_C);" << std::endl;
        src << "extern const uint8_t " << (MAP_NAME + "_tiles16_flag_trigger") << "[256][2][2][8];" << std::endl;

        src << "#define MAP_TILES16_DAMG " << (MAP_NAME + "_tiles16_flag_damage") << std::endl;
        src << "USING_MODULE("  << (MAP_NAME + "_tiles16_flag_damage") << ", PAGE_C);" << std::endl;
        src << "extern const uint8_t " << (MAP_NAME + "_tiles16_flag_damage") << "[256][2][2][8];" << std::endl;

        src << "#define MAP_TILES8L " << (MAP_NAME + "_tiles8L") << std::endl;
        src << "USING_MODULE("  << (MAP_NAME + "_tiles8L") << ", PAGE_C);" << std::endl;
        src << "extern const uint8_t " << (MAP_NAME + "_tiles8L") << "[256][2][16];" << std::endl;

        src << "#define MAP_TILES8R " << (MAP_NAME + "_tiles8R") << std::endl;
        src << "USING_MODULE("  << (MAP_NAME + "_tiles8R") << ", PAGE_C);" << std::endl;
        src << "extern const uint8_t " << (MAP_NAME + "_tiles8R") << "[256][2][16];" << std::endl;


        src << "#include <map_implementation.t>" << std::endl;
    }
    
    // Spawn Animated Tiles
    {
        std::ofstream ofs(MAP_NAME + std::string("_animated") + ".c");

        ofs << "#include <stdint.h>" << std::endl;        
        ofs << "const uint8_t " << (MAP_NAME + std::string("_animated")) << "[" << NUM_ANIMATED_FRAMES << "][2][" << NUM_ANIMATED_TILES * 16 << "];" << std::endl;
        ofs << "const uint8_t " << (MAP_NAME + std::string("_animated")) << "[" << NUM_ANIMATED_FRAMES << "][2][" << NUM_ANIMATED_TILES * 16 << "] = {" << std::endl;

        for (size_t i=0; i<NUM_ANIMATED_FRAMES; i++) { 
            ofs << "{";
            for (size_t j=0; j<2; j++) { 
                ofs << "{";
                for (size_t k=0; k<NUM_ANIMATED_TILES; k++) {
                    auto p = animatedTiles[k][i].msx1_interlaced;
                    
                    if (j==0) {
                        for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[0].pattern[j]); ofs << msg; }
                        for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[1].pattern[j]); ofs << msg; }                        
                    } else {
                        for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[0].color[j]);   ofs << msg; }
                        for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[1].color[j]);   ofs << msg; }
                    }
                }
                ofs << "}," << std::endl << " ";
            }
            ofs << "}," << std::endl << " ";
        }
        ofs << "};" << std::endl;
    }

    // Spawn Maps
    {
        for (size_t m=0; m<maps.size(); m++) {
            
            {
                auto &map16 = maps[m].map16;
                
                std::ofstream ofs(MAP_NAME + "_map" + char('0'+m) + "_map16" + ".c");
                ofs << "#include <stdint.h>" << std::endl;
                ofs << "const uint8_t " << (MAP_NAME + "_map" + char('0'+m) + "_map16") << "[" << MAP16_Y << "]["<< MAP16_X << "];" << std::endl;
                ofs << "const uint8_t " << (MAP_NAME + "_map" + char('0'+m) + "_map16") << "[" << MAP16_Y << "]["<< MAP16_X << "] = {" << std::endl;
                
                for (int i=0; i<map16.rows; i++) { 
                    
                    ofs << "{";
                    for (int j=0; j<map16.cols; j++) {

                        //if (j and (j%16==0)) ofs << std::endl << " "; 
                        sprintf(msg,"0x%02X,", map16(i,j)); ofs << msg;
                    }
                    ofs << "}," << std::endl; 
                }
                ofs << "};" << std::endl;
            }
        }
    }
        
    // Spawn tile16
    {
        std::ofstream ofs(MAP_NAME + "_tiles16" + ".c");
        ofs << "#include <stdint.h>" << std::endl;
        ofs << "const uint8_t " << (MAP_NAME + "_tiles16") << "[256][2][2];" << std::endl;
        ofs << "const uint8_t " << (MAP_NAME + "_tiles16") << "[256][2][2] = {" << std::endl;
        
        for (size_t i=0; i<tiles16.size(); i++) {

            if (i and (i%4==0)) ofs << std::endl; 
            sprintf(msg,"{ { 0x%04X, 0x%04X}, { 0x%04X, 0x%04X} }, ", tiles16[i].idx(0,0), tiles16[i].idx(0,1), tiles16[i].idx(1,0), tiles16[i].idx(1,1));
            ofs << msg;
        }
        ofs << "};" << std::endl;
        ofs << "const uint8_t " << (MAP_NAME + "_tiles16_filler") << "[7*1024] = { 0 };" << std::endl;
    }

    // Spawn tile16_flags
    {

		for (int f=0; f<16; f++) {
			
			std::ostringstream name_stream;
			name_stream << MAP_NAME << "_tiles16_flags_" << f;
			std::string name = name_stream.str();
			 
			std::ofstream ofs(name + ".c");
			ofs << "#include <stdint.h>" << std::endl;
			ofs << "const uint8_t " << name << "[16][256];" << std::endl;
			ofs << "const uint8_t " << name << "[16][256] = {" << std::endl;
			
			for (size_t i=0; i<16; i++) {

				ofs << "{ ";
				for (size_t t=0; t<tiles16.size(); t++) {
					
					uint8_t flags = 0;
					if (tiles16[t].flags(f,i)[1]<128) flags += 1;
					if (tiles16[t].flags(f,i)[0]>128) flags += 2;
					if (tiles16[t].flags(f,i)[2]>128) flags += 4;
					sprintf(msg,"0x%02X, ", flags);
					ofs << msg;
				}
				ofs << "}, " << std::endl;
			}
			ofs << "};" << std::endl;
			
			ofs << "const uint8_t "<< name << "_filler[4*1024] = { 0 };" << std::endl;
		}


		{
			std::ofstream ofs(MAP_NAME + "_tiles16_flag_traversability" + ".c");
			ofs << "#include <stdint.h>" << std::endl;
			ofs << "const uint8_t " << (MAP_NAME + "_tiles16_flag_traversability") << "[256][2][2][8];" << std::endl;
			ofs << "const uint8_t " << (MAP_NAME + "_tiles16_flag_traversability") << "[256][2][2][8] = {" << std::endl;
			
			for (size_t i=0; i<tiles16.size(); i++) {

				if (i) ofs << std::endl; 
				ofs << "{ ";
				for (size_t ii=0; ii<2; ii++) {
					ofs << "{ ";
					for (size_t jj=0; jj<2; jj++) {
						ofs << "{ ";
						for (size_t j=0; j<8; j++) {
							int val = 0;
							for (size_t k=0; k<8; k++) {
								val *= 2;
								if (tiles16[i].flags(ii*8+j,jj*8+k)[1]>128) {
									val++;
								}
							}
							sprintf(msg,"0x%02X, ", val);
							ofs << msg;
						}
						ofs << "}, ";
					}
					ofs << "}, ";
				}
				ofs << "}, ";
			}
			ofs << "};" << std::endl;
		}

		{
			std::ofstream ofs(MAP_NAME + "_tiles16_flag_trigger" + ".c");
			ofs << "#include <stdint.h>" << std::endl;
			ofs << "const uint8_t " << (MAP_NAME + "_tiles16_flag_trigger") << "[256][2][2][8];" << std::endl;
			ofs << "const uint8_t " << (MAP_NAME + "_tiles16_flag_trigger") << "[256][2][2][8] = {" << std::endl;
			
			for (size_t i=0; i<tiles16.size(); i++) {

				if (i) ofs << std::endl; 
				ofs << "{ ";
				for (size_t ii=0; ii<2; ii++) {
					ofs << "{ ";
					for (size_t jj=0; jj<2; jj++) {
						ofs << "{ ";
						for (size_t j=0; j<8; j++) {
							int val = 0;
							for (size_t k=0; k<8; k++) {
								val *= 2;
								if (tiles16[i].flags(ii*8+j,jj*8+k)[0]>128) {
									val++;
								}
							}
							sprintf(msg,"0x%02X, ", val);
							ofs << msg;
						}
						ofs << "}, ";
					}
					ofs << "}, ";
				}
				ofs << "}, ";
			}
			ofs << "};" << std::endl;
		}

		{
			std::ofstream ofs(MAP_NAME + "_tiles16_flag_damage" + ".c");
			ofs << "#include <stdint.h>" << std::endl;
			ofs << "const uint8_t " << (MAP_NAME + "_tiles16_flag_damage") << "[256][2][2][8];" << std::endl;
			ofs << "const uint8_t " << (MAP_NAME + "_tiles16_flag_damage") << "[256][2][2][8] = {" << std::endl;
			
			for (size_t i=0; i<tiles16.size(); i++) {

				if (i) ofs << std::endl; 
				ofs << "{ ";
				for (size_t ii=0; ii<2; ii++) {
					ofs << "{ ";
					for (size_t jj=0; jj<2; jj++) {
						ofs << "{ ";
						for (size_t j=0; j<8; j++) {
							int val = 0;
							for (size_t k=0; k<8; k++) {
								val *= 2;
								if (tiles16[i].flags(ii*8+j,jj*8+k)[2]>128) {
									val++;
								}
							}
							sprintf(msg,"0x%02X, ", val);
							ofs << msg;
						}
						ofs << "}, ";
					}
					ofs << "}, ";
				}
				ofs << "}, ";
			}
			ofs << "};" << std::endl;
		}
	}
    
    // Spawn tile8L
    {
        std::ofstream ofs(MAP_NAME + "_tiles8L" + ".c");
        ofs << "#include <stdint.h>" << std::endl;
        ofs << "const uint8_t " << (MAP_NAME + "_tiles8L") << "[256][2][16];" << std::endl;
        ofs << "const uint8_t " << (MAP_NAME + "_tiles8L") << "[256][2][16] = {" << std::endl;

        for (auto &tile8 : tiles8L) { ofs << "{";

                auto p = tile8.msx1_interlaced;
                
                ofs << "{";
                    for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[0].pattern[j]); ofs << msg; }
                    for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[1].pattern[j]); ofs << msg; }
                ofs << "}," << std::endl;
                ofs << "  {";
                    for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[0].color[j]);   ofs << msg; }
                    for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[1].color[j]);   ofs << msg; }
                ofs << "}";
        ofs << "}," << std::endl; }
        ofs << "};" << std::endl;
    }

    // Spawn tile8R
    {
        std::ofstream ofs(MAP_NAME + "_tiles8R" + ".c");
        ofs << "#include <stdint.h>" << std::endl;
        ofs << "const uint8_t " << (MAP_NAME + "_tiles8R") << "[256][2][16];" << std::endl;
        ofs << "const uint8_t " << (MAP_NAME + "_tiles8R") << "[256][2][16] = {" << std::endl;

        for (auto &tile8 : tiles8R) { ofs << "{";

                auto p = tile8.msx1_interlaced;
                
                ofs << "{";
                    for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[0].pattern[j]); ofs << msg; }
                    for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[1].pattern[j]); ofs << msg; }
                ofs << "}," << std::endl;
                ofs << "  {";
                    for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[0].color[j]);   ofs << msg; }
                    for (int j=0; j<8; j++) { sprintf(msg,"0x%02X,", p[1].color[j]);   ofs << msg; }
                ofs << "}";
        ofs << "}," << std::endl; }
        ofs << "};" << std::endl;
    }

}

