#include <iostream>
#include <string>
#include <algorithm>

std::string result;

void highPrecisionSummation(std::string s1, std::string s2) {
    int carry = 0;
    int MAX = std::max(s1.length(), s2.length());
    result.clear();

    for (int i = 0; i < MAX; i++) {
        int digit1 = (i < s1.length()) ? (s1[s1.length() - 1 - i] - '0') : 0;
        int digit2 = (i < s2.length()) ? (s2[s2.length() - 1 - i] - '0') : 0;
        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        sum = sum % 10;
        char aux = (char)(sum + '0'); 
        result = aux + result;
    }

    if (carry > 0) {
        char aux = (char)(carry + '0'); 
        result = aux + result;
    }

    for (char c : result) {
        std::cout << c;
    }
}

int main() {
    std::string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);

    highPrecisionSummation(s1, s2);
}
