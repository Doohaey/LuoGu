#include <cstdio>
#include <map>

std::map<int, int> values;
typedef std::map<int, int>::iterator itr;

int main() {
    int n;
    scanf("%d", &n);
    int minLength = n + 1;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        values[x]++;
    }

    while (!values.empty()) {
        int sizeOfGroup = 0;
        itr pre = values.begin(), post = values.begin();
        --pre->second;
        ++sizeOfGroup;

        for (++post; post != values.end() && (pre->first == post->first - 1) && (pre->second < post->second); ++pre, ++post) {
            --post->second;
            ++sizeOfGroup;
        }

        itr i = values.begin();
        while (i != values.end() && i->second == 0){
            values.erase(i++->first);
        }

        if (sizeOfGroup < minLength) {
            minLength = sizeOfGroup;
        }
    }

    printf("%d", minLength);

    return 0;
}



