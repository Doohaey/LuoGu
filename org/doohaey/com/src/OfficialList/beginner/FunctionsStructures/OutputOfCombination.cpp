#include <iostream>
#include <iomanip>
#include <vector>

void dfs(int cur, int tot, std::vector<int>& path, int n, int r) {
    if(tot == r) {
        for(int i=0; i<path.size(); i++) {
            std::cout << std::setw(3) << path[i];
        }
        std::cout << std::endl;
        return;
    }

    for(int i=cur; i<=n; i++) {
        path.push_back(i);
        dfs(i+1, tot+1, path, n, r);
        path.pop_back();
    }
}

int main() {
    int n, r;
    std::cin >> n >> r;
    std::vector<int> path;
    dfs(1, 0, path, n, r);

    return 0;
}
