#include <iostream>
#include <vector>
#include <cmath>

int size, count_solutions = 0;
std::vector<int> position;

void printVector() {
    for (int i = 0; i < size; i++) {
        std::cout << position[i] + 1 << (i == size - 1 ? "\n" : " ");
    }
}

bool check(int queenNum) {
    for (int i = 0; i < queenNum; i++) {
        if (position[i] == position[queenNum] || std::abs(position[i] - position[queenNum]) == queenNum - i) {
            return false;
        }
    }
    return true;
}

void queens(int k) {
    if (k == size) {
        count_solutions++;
        if (count_solutions <= 3) {
            printVector();
        }    
    } else {
        for (int i = 0; i < size; i++) {
            position[k] = i;
            if (check(k)) {
                queens(k + 1);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> size;
    position.resize(size);
    queens(0);

    std::cout << count_solutions << std::endl;

    return 0;
}
