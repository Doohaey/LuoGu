#include <iostream>
#include <string>

void incrementOfBoys(std::string s, int &boyCount){
    for (int i = 0; i < s.length() - 2; i++){
        if (s[i]=='b'|| s[i+1]=='o' || s[i+2]=='y'){
            boyCount++;
        }
    }
}

void incrementOfGirls(std::string s, int &girlCount){
    for (int j = 0; j < s.length() - 3; j++){
        if (s[j] == 'g' || s[j+1] == 'i' || s[j+2] == 'r' || s[j+3] == 'l'){
            girlCount++;
        }
    }
}

int main(){
    int boyCount = 0,girlCount = 0;
    std::string s;
    std::getline(std::cin,s);

    incrementOfBoys(s,boyCount);
    incrementOfGirls(s,girlCount);

    std::cout<<boyCount<<std::endl<<girlCount; 
}