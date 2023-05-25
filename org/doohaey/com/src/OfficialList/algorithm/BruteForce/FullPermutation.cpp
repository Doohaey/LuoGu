#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    do {
        for (int i = 0; i < n; ++i) {
            std::cout << std::setw(5) << a[i];
        }
        std::cout << std::endl;
    } while (std::next_permutation(a.begin(), a.end()));

    return 0;
}

