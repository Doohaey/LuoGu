#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>

const int MAXN = 16;

int n;
double dist[MAXN][MAXN];
double bitmasking[MAXN][32770];  // 2^15 = 32768，稍微大一点就是 32770
struct Point {
    double x, y;
} p[MAXN];

double distance(Point a, Point b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    p[0].x = 0;
    p[0].y = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (i == j){
                dist[i][j] = 0;
            } else {
                dist[i][j] = distance(p[i],p[j]);
                dist[j][i] = dist[i][j];
            }
        }
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < (1 << n); j++){
            bitmasking[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= n; i++){
        bitmasking[i][1 << (i-1)] = dist[0][i];
    }

    for (int l = 1; l < (1 << n); l++){
        for (int i = 1; i <= n; i++){
            if ((l & (1 << (i - 1))) != 0){
                for (int j = 1; j <= n; j++){
                    if (i != j && (l & (1 << (j - 1))) != 0){
                        bitmasking[i][l] = std::min(bitmasking[i][l], bitmasking[j][l ^ (1 << (i - 1))] + dist[j][i]);
                    }
                }
            }
        }
    }

    double res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        res = std::min(res, bitmasking[i][(1 << n) - 1]);
    }

    std::cout << std::fixed << std::setprecision(2) << res << std::endl;

    return 0;
}

