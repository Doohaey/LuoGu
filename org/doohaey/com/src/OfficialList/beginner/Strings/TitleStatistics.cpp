#include <iostream>
#include <sstream>
#include <string>

int main() {
    int count = 0;
    std::string input;
    std::getline(std::cin, input);  

    std::stringstream ss(input);    
    std::string word;
    while (ss >> word) count += word.length();
    std::cout<<count;

    return 0;
}
