#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string sSum,s1,s2,s3,s4;
    getline(std::cin,s1);
    getline(std::cin,s2);
    getline(std::cin,s3);
    getline(std::cin,s4);
    sSum = s1 + s2 + s3 + s4;

    int frequencyCount[26] = {0};

    for (char c : sSum){
        if (c >= 'A' && c <= 'Z') frequencyCount[c - 'A']++;
    }

    int max = 0;
    for (int count : frequencyCount) if (count > max) max = count;
    for (int i = max; i >= 1; i--){
        for (int j = 0; j < 26; j++){
            if (frequencyCount[j] >= i) std::cout<<'*';
            else std::cout<<" ";
            
            if (j != 25) std::cout<<" ";
        }
        std::cout<<"\n";
    }

    for (int k = 0; k < 26; k++) std::cout<<(char)(k + 'A')<<" ";

    return 0;
}