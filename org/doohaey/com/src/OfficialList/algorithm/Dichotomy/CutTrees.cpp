#include <iostream>
#include <vector>
#include <algorithm>

typedef long long llg;

llg n, m, height_saw;
std::vector<llg> height_trees;

bool check(llg mid) {
    llg sum = 0;
    for (llg height_tree : height_trees) {
        if (height_tree > mid) {
            sum += height_tree - mid;
        }
    }

    return sum >= m;
}

int main() {
    std::cin >> n >> m;
    height_trees.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> height_trees[i];
    }
    std::sort(height_trees.begin(), height_trees.end());

    llg l = 0, r = height_trees[n - 1];
    while (l <= r) {
        llg mid = l + (r - l) / 2;

        if (check(mid)) {
            height_saw = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    std::cout << height_saw << std::endl;

    return 0;
}
