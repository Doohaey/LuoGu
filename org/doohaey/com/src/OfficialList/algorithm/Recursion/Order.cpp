#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> menu(N);
    for(int i = 0; i < N; i++) {
        std::cin >> menu[i];
    }

    std::vector<int> dp(M+1, 0);
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = M; j >= menu[i]; j--) {
            dp[j] += dp[j - menu[i]];
        }
    }

    std::cout << dp[M] << std::endl;
    return 0;
}
