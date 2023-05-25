#include <iostream>
#include <algorithm>

int a, b, c;
int num[10], vis[10];
bool flag = false;

void check() {
    int x = num[1] * 100 + num[2] * 10 + num[3];
    int y = num[4] * 100 + num[5] * 10 + num[6];
    int z = num[7] * 100 + num[8] * 10 + num[9];
    if (x * b == y * a && y * c == z * b) {
        std::cout << x << " " << y << " " << z << std::endl;
        flag = true;
    }
}

void dfs(int x) {
    if(x == 10) {
        check();
        return;
    }
    for(int i = 1; i <= 9; i++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            num[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    std::cin >> a >> b >> c;
    dfs(1);
    if (!flag) {
        std::cout << "No!!!" << std::endl;
    }
    return 0;
}
