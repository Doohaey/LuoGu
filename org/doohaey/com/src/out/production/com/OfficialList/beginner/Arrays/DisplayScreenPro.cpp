#include <iostream>
using namespace std;

char digits[100];
char displayScreen[5][400];

void load(int n);
void display();

int main() {
    int n;
    cin >> n;
    cin >> digits;

    load(n);
    display();

    return 0;
}

// 加载数字序列
void load(int n) {
    for (int i = 0; i < n; i++) {
        int digit = digits[i] - '0';
        const char pattern[] = {
            'X', 'X', 'X', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', 'X', 'X', 'X',
            '.', '.', 'X', '.', '.', 'X', '.', '.', 'X', '.', '.', 'X', '.', '.', 'X',
            'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X',
            'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X',
            'X', '.', 'X', 'X', '.', 'X', 'X', 'X', 'X', '.', '.', 'X', '.', '.', 'X',
            'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X',
            'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X', '.', 'X', 'X', 'X', 'X',
            'X', 'X', 'X', '.', '.', 'X', '.', '.', 'X', '.', '.', 'X', '.', '.', 'X',
            'X', 'X', 'X', 'X', '.', 'X', 'X', 'X', 'X', 'X', '.', 'X', 'X', 'X', 'X',
            'X', 'X', 'X', 'X', '.', 'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X'
        };

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 3; col++) {
                displayScreen[row][4 * i + col] = pattern[digit * 15 + row * 3 + col];
            }
            if (i != n - 1) {
                displayScreen[row][4 * i + 3] = '.';
            }
        }
    }
}

// 显示显示屏上的内容
void display() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < sizeof(displayScreen[0]); j++) {
            cout << displayScreen[i][j];
        }
        cout << endl;
    }
}


