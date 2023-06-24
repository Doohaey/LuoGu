#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cstdio>

int main() {
    int n, minLength = INT_MAX;
    scanf("%d", &n);
    std::vector<int> powerValue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &powerValue[i]);
    }

    std::sort(powerValue.begin(), powerValue.end());

    std::map<int, std::vector<int>> endValueToGroup;
    for (int i = 0; i < n; i++) {
        int value = powerValue[i];
        if (endValueToGroup.find(value - 1) != endValueToGroup.end()) {
            std::vector<int> &group = endValueToGroup[value - 1];
            group.push_back(value);
            endValueToGroup.erase(value - 1);
            endValueToGroup[value] = group;
        } else {
            std::vector<int> group = {value};
            endValueToGroup[value] = group;
        }
    }

    for (std::map<int, std::vector<int>>::iterator it = endValueToGroup.begin(); it != endValueToGroup.end(); ++it) {
        int size = it->second.size();
        if (size < minLength) {
            minLength = size;
        }
    }

    printf("%d\n", minLength);
}

