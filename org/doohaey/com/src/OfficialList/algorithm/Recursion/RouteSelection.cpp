#include <iostream>
#include <vector>
#include <algorithm>
#define SYSTEM_OF_NUMERATION 10

int m,n;
std::vector<std::vector<int>> parFibonacci;

std::vector<int> hpPlus(std::vector<int> a, std::vector<int> b){
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

int main(){
    std::cin >> m >> n;
    
    if (n - m > 2){
        parFibonacci.resize(n + 1);
        parFibonacci[m] = {0};
        parFibonacci[m+1] = {1};
        parFibonacci[m+2] = {2};  
        for (int i = m + 3; i <= n; i++){
            parFibonacci[i] = hpPlus(parFibonacci[i-1],parFibonacci[i-2]);
        }
        for (int j = 0; j < parFibonacci[n].size(); j++){
            std::cout<< parFibonacci[n][parFibonacci[n].size() - j - 1];
        }
    }else std::cout << 1;

    return 0;
}