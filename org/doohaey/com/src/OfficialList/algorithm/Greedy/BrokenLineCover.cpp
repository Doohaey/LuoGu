#include <iostream>
#include <vector>
#include <algorithm>

struct Match {
    int start;
    int end;
};

bool compare(Match a, Match b) {
    return a.end < b.end;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Match> matches(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> matches[i].start >> matches[i].end;
    }

    std::sort(matches.begin(), matches.end(), compare);

    int res = 0, currentEnd = -1;
    for(int i = 0; i < n; ++i) {
        if(matches[i].start >= currentEnd) {
            currentEnd = matches[i].end;
            ++res;
        }
    }

    std::cout << res;
    return 0;
}
