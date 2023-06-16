#include <iostream>
#include <vector>
#include <climits>

int n, sum = 0;
std::vector<int> heaps;

void merge() {
    int min1 = INT_MAX, min2 = INT_MAX, index1 = -1, index2 = -1;

    for (int i = 0; i < heaps.size(); i++) {
        if (heaps[i] < min1) {
            min2 = min1;
            index2 = index1;
            min1 = heaps[i];
            index1 = i;
        } else if (heaps[i] < min2) {
            min2 = heaps[i];
            index2 = i;
        }
    }

    if (index1 != -1 && index2 != -1) {
        sum += min1 + min2;
        heaps[index1] = min1 + min2;
        heaps.erase(heaps.begin() + index2);
        --n;
    }
}

int main() {
    std::cin >> n;
    heaps.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heaps[i];
    }

    while (n > 1) {
        merge();
    }

    std::cout << sum << std::endl;
    return 0;
}
