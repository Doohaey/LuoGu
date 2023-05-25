#include <iostream>
#include <cmath>

int listOfPeople[1024][1024];

void initializeMatrix(int n, int &len) {
    len = std::pow(2, n);
    for (size_t i = 0; i < len; i++) {
        for (size_t j = 0; j < len; j++) {
            listOfPeople[i][j] = 1;
        }
    }
}

void amnesty(int iniX, int lenX, int iniY, int lenY) {
    for (size_t k = iniX; k < iniX + lenX / 2; k++) {
        for (size_t l = iniY; l < iniY + lenY / 2; l++) {
            listOfPeople[k][l] = 0;
        }
    }
    if (lenX / 2 > 1) {
        amnesty(iniX + lenX / 2, lenX / 2, iniY, lenY / 2);
        amnesty(iniX, lenX / 2, iniY + lenY / 2, lenY / 2);
        amnesty(iniX + lenX / 2, lenX / 2, iniY + lenY / 2, lenY / 2);
    }
}


void printMatrix(int len) {
    for (size_t m = 0; m < len; m++) {
        for (size_t n = 0; n < len; n++) {
            std::cout << listOfPeople[m][n];
            if (n != len - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, len;
    std::cin >> n;
    initializeMatrix(n, len);
    amnesty(0, len, 0, len);
    printMatrix(len);
}
