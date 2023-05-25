#include <iostream>

long long catalan[18] = {1};

int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    std::cout << catalan[n] << std::endl;

    return 0;
}
