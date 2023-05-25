#include <iostream>
#include <string>
#include <map>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::map<char, int> variables = {{'a', 0}, {'b', 0}, {'c', 0}};

    for (size_t i = 0; i < input.length(); i++) {
        char var = input[i];
        i += 3;

        char value = input[i];
        if (isdigit(value)) {
            variables[var] = value - '0';
        } else {
            variables[var] = variables[value];
        }

        i += 1;
    }

    std::cout << variables['a'] << " " << variables['b'] << " " << variables['c'] << std::endl;

    return 0;
}
