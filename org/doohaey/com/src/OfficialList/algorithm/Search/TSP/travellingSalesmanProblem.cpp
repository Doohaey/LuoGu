#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>

const int MAXN = 16;
const int INF = 1e9;
int n;
double f[1 << MAXN][MAXN], dis[MAXN][MAXN];
struct Point {
    int x, y;
} p[MAXN];

double distance(Point a, Point b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dis[i][j] = dis[j][i] = distance(p[i], p[j]);
        }
    }
    std::fill(f[0], f[0] + (1 << n) * n, INF);
    f[1][1] = 0;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j <= n; j++) {
            if ((i >> (j - 1)) & 1) {
                for (int k = 0; k < n; k++) {
                    if ((i ^ (1 << (j - 1))) >> k & 1) {
                        f[i][j] = std::min(f[i][j], f[i ^ (1 << (j - 1))][k + 1] + dis[k + 1][j]);
                    }
                }
            }
        }
    }
    double res = INF;
    for (int i = 1; i <= n; i++) {
        res = std::min(res, f[(1 << n) - 1][i] + dis[i][1]);
    }
    std::cout << std::fixed << std::setprecision(2) << res << std::endl;


    return 0;
}
