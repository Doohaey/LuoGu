#include <iostream>
#include <vector>
#include <algorithm>

#define DIGIT 500
int result[DIGIT + 1] = {0};

void stringToArray(std::string initial, int initialNum[]){
    for (int i = 0; i < initial.length(); i++){
        initialNum[i] = initial[initial.length() - i - 1] - '0'; 
    }
}

void highPrecisionSummmation(std::string s1, std::string s2){
    int num1[DIGIT] = {0};
    int num2[DIGIT] = {0};
    result[DIGIT+1] = {0};
    stringToArray(s1,num1);
    stringToArray(s2,num2);

    int carry = 0, MAX = std::max(s1.length(),s2.length());
    for (int j = 0; j < MAX; j++){
        int digit1 = (j < s1.length()) ? num1[j] : 0;
        int digit2 = (j < s2.length()) ? num2[j] : 0;
        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        result[j] = sum % 10;
    }

    if (carry > 0) {
        result[MAX] = carry;
    } else {
        result[MAX] = 0;
    }
}

void printResult(int result[]){
    bool startPrint = false;
    for (int k = DIGIT + 1; k >= 0; k--){
        if (result[k] != 0) startPrint = true;
        if (startPrint) std::cout<<result[k];
    }
}

int main(){
    std::string s1,s2;
    getline(std::cin,s1);
    getline(std::cin,s2);

    highPrecisionSummmation(s1,s2);
    printResult(result);
}