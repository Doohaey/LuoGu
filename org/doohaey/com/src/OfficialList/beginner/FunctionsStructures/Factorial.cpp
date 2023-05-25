#include <iostream>

int factorial(int input){
    if (input > 1) return factorial(input - 1) * input;
    if (input == 1) return 1;
}

int main(){
    int input,output;
    std::cin>>input;
    output = factorial(input);
    std::cout<<output;
}