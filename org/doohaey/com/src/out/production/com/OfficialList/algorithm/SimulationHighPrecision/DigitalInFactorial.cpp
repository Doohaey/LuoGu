#include <iostream>
#include <vector>

#define SYSTEM_OF_NUMERATION 10

std::vector<int> hpMultiply(std::vector<int> factor1, int factor2){
    int carry = 0;

    for (int i = 0; i < factor1.size(); i++){
        factor1[i] =  factor1[i] * factor2 + carry;
        carry = 0;

        if (factor1[i] >= SYSTEM_OF_NUMERATION){
            carry = factor1[i] / SYSTEM_OF_NUMERATION;
            factor1[i] = factor1[i] % SYSTEM_OF_NUMERATION;
        }
    }

    while (carry > 0){
        factor1.push_back(carry % SYSTEM_OF_NUMERATION);
        carry /= SYSTEM_OF_NUMERATION;
    }
    return factor1;
}

std::vector<int> hpFactorial(int numFac){
    if (numFac > 1) return hpMultiply(hpFactorial(numFac - 1),numFac);
    else return {1};
}    

void outTimes(int numFac, int digit){
    std::vector<int> s = hpFactorial(numFac);
    
    int count = 0 ;
    for (int i : s){
        if (i == digit) count++;
    }
    std::cout<<count;
}

int main(){
    int num;
    std::cin>>num;

    for (int i = 0; i < num; i++){
        int numFac,digit;
        std::cin>>numFac>>digit;
        outTimes(numFac,digit);
    }
}