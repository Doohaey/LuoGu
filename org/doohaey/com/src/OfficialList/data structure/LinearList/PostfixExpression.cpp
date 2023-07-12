#include <iostream>
#include <cstdio>

int post_expression[1000];

int main(){
    int i = -1, number = 0;
    char c;
    while ((c = getchar()) != '@'){
        if (c == '.'){
            post_expression[++i] = number;
            number = 0;
        } else if (c == '+'){
            post_expression[--i] += post_expression[i+1];
        } else if (c == '-'){
            post_expression[--i] -= post_expression[i+1];
        } else if (c == '*'){
            post_expression[--i] *= post_expression[i+1];
        } else if (c == '/'){
            post_expression[--i] /= post_expression[i+1];
        } else {
            number = number * 10 + (c - '0');
        }
    }

    std::cout << post_expression[0];

    return 0;
}