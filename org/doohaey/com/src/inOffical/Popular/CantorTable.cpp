#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int line = 0, count = 0;
    while (count < N) {
        ++line;
        count += line;
    }

    int num = count - N + 1;
    int den = line - num + 1;

    if (line % 2 == 0) {
        std::cout << den << '/' << num << std::endl;
    } else {
        std::cout << num << '/' << den << std::endl;
    }

    return 0;
}

