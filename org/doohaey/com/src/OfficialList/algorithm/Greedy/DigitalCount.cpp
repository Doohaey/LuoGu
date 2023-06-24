#include <cstdio>
#include <string>

std::string N;
int left;

void stringDelete() {
    int i = 0;
    while (left > 0 && i < N.size() - 1) {
        if (N[i] > N[i + 1]) {
            N.erase(N.begin() + i);
            left--;
            if (i > 0) {
                i--;
            }
        } else {
            i++;
        }
    }

    if (left >= N.size()) {
        N.clear();
    } else {
        while (left > 0) {
            N.pop_back();
            left--;
        }
    }

    while (N[0] == '0' && N.size() != 1) {
        N.erase(N.begin());
    }
}

int main() {
    char input[100];
    scanf("%s", input);
    N = input;

    scanf("%d", &left);

    stringDelete();

    printf("%s", N.c_str());

    return 0;
}

