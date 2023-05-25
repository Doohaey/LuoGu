#include <iostream>

int matchStickNum[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, cnt = 0;

int getSticks(int num) {
    int total = 0;
    if (num == 0) return matchStickNum[0];
    while (num) {
        total += matchStickNum[num % 10];
        num /= 10;
    }
    return total;
}

int main() {
    std::cin >> n;
    n -= 4;

    for (int A = 0; A <= 711; ++A) {
        for (int B = 0; B <= 711; ++B) {
            int C = A + B;
            if (getSticks(A) + getSticks(B) + getSticks(C) == n) {
                cnt++;
            }
        }
    }

    std::cout << cnt << std::endl;
    return 0;
}
