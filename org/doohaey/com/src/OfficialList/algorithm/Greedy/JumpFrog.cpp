#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int n;
long long sum = 0;
std::vector<int> stoneHeight;

int main() {
    std::cin >> n;
    stoneHeight.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> stoneHeight[i];
    }

    stoneHeight.insert(stoneHeight.begin(), 0);
    std::sort(stoneHeight.begin(), stoneHeight.end());

    int lowerBound = 0, upperBound = n;
    while (lowerBound < upperBound){
        sum += std::pow(stoneHeight[upperBound] - stoneHeight[lowerBound],2);
        lowerBound++;
        sum += std::pow(stoneHeight[upperBound] - stoneHeight[lowerBound],2);
        upperBound--;
    }

    std::cout << sum << std::endl;

    return 0;
}
