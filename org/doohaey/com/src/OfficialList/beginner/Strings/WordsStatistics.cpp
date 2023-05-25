#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <cctype>

bool caseInsensitiveCompare(char a, char b) {
    return std::tolower(a) == std::tolower(b);
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    std::string wordToFind, passage;
    int count = 0, initialRecord = -1;
    std::cin >> wordToFind;
    std::cin.ignore();
    std::getline(std::cin, passage);

    if (passage.length() >= wordToFind.length()) {
        for (size_t i = 0; i <= passage.length() - wordToFind.length(); i++) {
            bool isEqual = true;
            for (size_t j = 0; j < wordToFind.length(); j++) {
                if (!caseInsensitiveCompare(passage[i + j], wordToFind[j])) {
                    isEqual = false;
                    break;
                }
            }
            
            if (isEqual && 
                (i == 0 || !isLetter(passage[i - 1])) && 
                (i + wordToFind.length() == passage.length() || !isLetter(passage[i + wordToFind.length()]))) {
                count++;
                if (initialRecord == -1) {
                    initialRecord = i;
                }
            }
        }
    }

    if (count == 0) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << count << " " << initialRecord << std::endl;
    }

    return 0;
}

