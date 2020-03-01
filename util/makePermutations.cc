#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double evaluatePermutation(const vector<vector<int>> &history, const vector<int> &v) {
    
    
    std::vector<uint> lastVisible(4);
    
    double cost = 0.;
    for (int i0=0; i0<16; i0++) {
        for (int i1=0; i1<16; i1++) {
            if (i1==i0) continue;
            for (int i2=0; i2<16; i2++) {
                if (i2==i0) continue;
                if (i2==i1) continue;
                for (int i3=0; i3<16; i3++) {
                    if (i3==i0) continue;
                    if (i3==i1) continue;
                    if (i3==i2) continue;
                    
                    for (auto &l : lastVisible) l = history.size()-9;
                    
                    for (uint h = history.size()-8; h<=history.size(); h++) {
                        
                        const vector<int> &p = (h==history.size()?v:history[h]);
                        uint visitedSprites = 0;
                        for (auto &pi : p) {
                            if (visitedSprites==2) break;
                            if (pi==i0) { lastVisible[0] = h; visitedSprites++; }
                            if (pi==i1) { lastVisible[1] = h; visitedSprites++; }
                            if (pi==i2) { lastVisible[2] = h; visitedSprites++; }
                            if (pi==i3) { lastVisible[3] = h; visitedSprites++; }
                        }
                    }
                    
                    for (auto &l : lastVisible) {
                        switch (history.size()-l) {
                        case 0:
                            break;
                        case 1:
                            break;
                        default:
                            cost += 1;
                        }
                        //cost += 1<<(2*(history.size()-l));
                    }
                }
            }
        }
    }
        
    
    return cost;
} 

int main() {
    
    vector<vector<int>> hist;
    vector<int> V;
    for (int i=0; i<16; i++) V.push_back(i);

    for (int i=0; i<16; i++) {
        std::random_shuffle(V.begin(), V.end());
        hist.push_back(V);
    }
    
    for (int i=0; i<512; i++) {
        double bestCost = 1e10;
        vector<int> bestCandidate;
        for (int i=0; i<(1<<9); i++) {
            std::random_shuffle(V.begin(), V.end());
            
            double cost = evaluatePermutation(hist, V);
            if (cost<bestCost) {
                bestCost = cost;
                bestCandidate = V;
            }
        }
        cerr << bestCost << std::endl;
        hist.push_back(bestCandidate);
    }
        
    cout << "static const uint8_t spritePermutations[256][16] = {" << std::endl;
    for (int i=0; i<256; i++) {
        cout << "{ ";
        for (auto &&v: hist[hist.size()+i-256]) cout << v << ", ";
        cout << "}, " << std::endl;
    }
    cout << "};" << std::endl;
}
