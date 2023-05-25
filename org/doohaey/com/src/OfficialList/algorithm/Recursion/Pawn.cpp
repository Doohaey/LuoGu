#include<iostream>
#include<cstring>

int fx[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int fy[9] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
int n, m, x, y;
long long dp[25][25];  // change int to long long to avoid overflow
bool a[25][25];

void initialize() {
    std::memset(a, 0, sizeof(a));
    a[x][y] = 1;
    for (int i = 0; i < 9; i++) {
        int dx = x + fx[i], dy = y + fy[i];
        if (dx >= 0 && dx <= n && dy >= 0 && dy <= m) {
            a[dx][dy] = 1;
        }
    }
}

void calculatePaths() {
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!a[i][j]) {
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
}

int main() {
    std::cin >> n >> m >> x >> y;
    initialize();
    calculatePaths();
    std::cout << dp[n][m] << std::endl;
    return 0;
}


