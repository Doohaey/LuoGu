#include <iostream>
#include <vector>

const int mod = 10000;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> f(N + 3, 0);
    f[1] = 1;
    f[2] = 2;
    f[3] = 5;
    for (int i = 4; i <= N; ++i) {
        f[i] = (2 * f[i - 1] + f[i - 3]) % mod;
    }
    std::cout << f[N] << std::endl;
    return 0;
}
