#include <iostream>
#include <iomanip>
#include <algorithm>

struct Heap{
    int weight,value;
    double ppr;
};

bool compare(const Heap& a, const Heap& b){
    return a.ppr > b.ppr;
}

int main(){
    int n,t;
    std::cin >> n >> t;

    Heap hps[n];

    for (int i = 0; i < n; i++){
        std::cin >> hps[i].weight >> hps[i].value;
        hps[i].ppr = static_cast<double>(hps[i].value) / hps[i].weight;
    }

    std::sort(hps, hps + n, compare);

    double loadedValue = 0;
    double loadedWeight = 0;
    for (int i = 0; i < n; i++){
        if (loadedWeight + hps[i].weight <= t){
            loadedWeight += hps[i].weight;
            loadedValue += hps[i].value;
        } else {
            loadedValue +=  (t - loadedWeight) * hps[i].ppr;
            break;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << loadedValue << std::endl;
    return 0;
}

