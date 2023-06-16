#include <iostream>
#include <vector>
#include <climits>

std::vector<int> subsidenceLevel;

void fillSubsi(int a, int b, int& dayCount){
    std::vector<int> minIndexs;
    int min = INT_MAX;
    for (int i = a;  i <= b; i++){
        if (subsidenceLevel[i] < min){
            min = subsidenceLevel[i];
            minIndexs.clear();
            minIndexs.push_back(i);
        } else if (subsidenceLevel[i] == min){
            minIndexs.push_back(i);
        }
    }

    dayCount += min;
    for (int i = a; i <= b; i++){
        subsidenceLevel[i] -= min;
    }

    int start = a;
    for (int i = 0; i < minIndexs.size(); i++){
        if (start < minIndexs[i]) fillSubsi(start, minIndexs[i] - 1, dayCount);
        start = minIndexs[i] + 1;
    }
    if (start <= b) fillSubsi(start, b, dayCount);
}

int main(){
    int n, dayCount = 0;
    std::cin >> n;
    subsidenceLevel.resize(n);
    for (int i = 0; i < n; i++){
        std::cin >> subsidenceLevel[i];
    }

    fillSubsi(0, n - 1, dayCount);

    std::cout << dayCount;
}
