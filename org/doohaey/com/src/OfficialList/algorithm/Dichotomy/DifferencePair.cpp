#include <iostream>
#include <unordered_map>

typedef long long llg;

int main(){
    int N, C;
    llg count = 0;
    std::cin >> N >> C;

    std::unordered_map<int,llg> digitCounts;
    for (int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        digitCounts[x]++;
    }

    for (auto pairs : digitCounts){
        int dif = pairs.first - C;
        if (dif > 0 && digitCounts.find(dif) != digitCounts.end()){
            count += pairs.second * digitCounts[dif];
        }
    }

    std::cout << count << std::endl;

    return 0;
}