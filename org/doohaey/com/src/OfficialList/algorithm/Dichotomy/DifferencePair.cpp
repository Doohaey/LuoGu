#include <iostream>
#include <unordered_map>

int main(){
    int N, C, count = 0;
    std::cin >> N >> C;

    std::unordered_map<int,int> digitCounts;
    for (int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        digitCounts[x]++;
    }

    for (auto pairs : digitCounts){
        int dif = pairs.first - C;
        if (dif > 0){
            count += pairs.second * digitCounts[dif];
        }
    }

    std::cout << count << std::endl;
}