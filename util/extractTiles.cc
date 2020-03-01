////////////////////////////////////////////////////////////////////////
// Image to MSX tiles
//
// Manuel Martinez (salutte@gmail.com)
//
// FLAGS: -std=gnu++14 -g `pkg-config opencv --cflags --libs` -Ofast -lpthread -fopenmp -lgomp -Wno-format-nonliteral

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <thread>
#include <chrono>
#include <functional>

using namespace std::chrono_literals;

int main(int argc, char *argv[]) {
	
	if (argc!=2) {
		std::cout << "Use: ./extractTiles name" << std::endl;
		return -1;
	}

    std::vector<std::pair<cv::Mat3b,size_t>> tiles;
    cv::Mat3b img = cv::imread(argv[1]);

    
    for (int i=0; i+15<img.rows; i+=16) {
        for (int j=0; j+15<img.cols; j+=16) {
            cv::Mat3b tile = img(cv::Rect(j,i,16,16)).clone();
            
            double dist = 1e10;
            size_t best = 0;
            for (uint k=0; k<tiles.size(); k++) {
                auto t = tiles[k].first;
                double n = cv::norm(tile-t) + cv::norm(t-tile);
                if (n<dist) {
                    dist = n;
                    best = k;
                }
            }
            
            if (dist > 1) {
                tiles.emplace_back(tile.clone(), 1);
            } else {
                tiles[best].second++;
            }
        }
    }
    
    size_t count = 0, minCount = 0;
    for (auto &t : tiles) {
        if (t.second > minCount) count++;
    }
    std::cout << tiles.size() << " " << count << std::endl;
    

    uint idx = 0;
    cv::Mat3b tileMap(16*ceil(double(count)/20), 16*20);
    for (auto &t : tiles) {
        if (t.second > minCount) {
            t.first.copyTo(tileMap(cv::Rect(16*(idx%20), 16*(idx/20), 16,16)));
            idx++;
        }
    }
    cv::imwrite("tileMap.png", tileMap);
    

	return 0;
}
