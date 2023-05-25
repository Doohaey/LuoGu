#include <iostream>
#include <algorithm>
#include <vector>
#define SYSTEM_OF_NUMERATION 10;

int n;
std::vector<std::vector<int>> fibonacci;

std::vector<int> hpSummation(std::vector<int> a, std::vector<int> b){
    int carry = 0;
    std::vector<int> summation;
    int size = std::max(a.size(),b.size());
    a.resize(size, 0);
    b.resize(size, 0);
    for (int i = 0; i < size; i++){
        int partSum = a[i] + b[i] + carry;
        carry = partSum / SYSTEM_OF_NUMERATION;
        partSum %= SYSTEM_OF_NUMERATION;
        summation.push_back(partSum);
    }
    if (carry > 0){
        summation.push_back(carry);
    }
    return summation;
}

void hpFibonacci(int i){
    if (i <= 3){
        std::vector<int> temp;
        temp.push_back(i);
        fibonacci.push_back(temp);
    }else{
         fibonacci.push_back(hpSummation(fibonacci[i-2],fibonacci[i-3]));
    }

}

int main(){
    std::cin >> n;
    for (int i = 1; i <= n; i++){
        hpFibonacci(i);
    }
    for (int j = 0; j < fibonacci[n-1].size(); j++){
        std::cout<<fibonacci[n-1][fibonacci[n-1].size() - j - 1];
    }
}