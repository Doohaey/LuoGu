#include <iostream>
#include <vector>

const int MOD = 1e9+7;

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> count(5001, 0);
    for (int i = 0; i < n; i++) {
        int length;
        std::cin >> length;
        count[length]++;
    }

    long long total = 0;
    for (int i = 1; i <= 5000; i++) {
        for (int j = i; j <= 5000 - i; j++) {
            long long k = count[j];
            if (i == j) {
                k = (k * (k - 1)) / 2;
            } else {
                k *= count[i];
            }
            k %= MOD;
            total = (total + k * ((count[i + j] * (count[i + j] - 1)) / 2 % MOD)) % MOD;
        }
    }

    std::cout << total << std::endl;

    return 0;
}
