#include <iostream>
#include <string>
#include <algorithm>

std::string expandString(int p1, int p2, int p3, const std::string& s) {
    std::string result;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];

        if (c != '-') {
            result.push_back(c);
        } else {
            if (i > 0 && i < s.length() - 1 && ((islower(s[i - 1]) && islower(s[i + 1])) || (isdigit(s[i - 1]) && isdigit(s[i + 1]))) && s[i + 1] > s[i - 1]) {
                std::string expansion;
                for (char ch = s[i - 1] + 1; ch < s[i + 1]; ++ch) {
                    char expandedChar;
                    if (p1 == 1) {
                        expandedChar = tolower(ch);
                    } else if (p1 == 2) {
                        expandedChar = toupper(ch);
                    } else {
                        expandedChar = '*';
                    }

                    for (int k = 0; k < p2; ++k) {
                        expansion.push_back(expandedChar);
                    }
                }

                if (p3 == 2) {
                    std::reverse(expansion.begin(), expansion.end());
                }
                result.append(expansion);
            } else {
                result.push_back(c);
            }
        }
    }
    return result;
}

int main() {
    int p1, p2, p3;
    std::string s;
    std::cin >> p1 >> p2 >> p3;
    std::cin.ignore();
    std::getline(std::cin, s);

    std::string result = expandString(p1, p2, p3, s);
    std::cout << result << std::endl;

    return 0;
}
