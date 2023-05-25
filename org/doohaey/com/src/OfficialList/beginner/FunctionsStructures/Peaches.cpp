#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int peaches = 1;

    for (int i = 1; i < n; ++i) {
        peaches = 2 * (peaches + 1);
    }

    std::cout << peaches << std::endl;
    return 0;
}
