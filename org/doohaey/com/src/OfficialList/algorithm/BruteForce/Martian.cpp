#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> fingerOrder(n);
    for (int i = 0; i < n; i++) {
        std::cin >> fingerOrder[i];
    }
    for (int i = 0; i < m; i++) {
        next_permutation(fingerOrder.begin(), fingerOrder.end());
    }
    for (int i = 0; i < n; i++) {
        std::cout << fingerOrder[i] << (i < n - 1 ? ' ' : '\n');
    }

    return 0;
}
