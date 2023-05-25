#include <iostream>
#include <algorithm>
#include <cstring>

bool scmp(const int a,const int b){
    std::string A,B;
    A = std::to_string(a);
    B = std::to_string(b);
    return A + B > B + A;
}

int main(){
    int n;
    std::cin>>n;
    int digitals[n];
    for (int i = 0; i < n; i++) std::cin>>digitals[i];
    std::sort(digitals,digitals+n,scmp);
    for (int i = 0; i < n; i++) std::cout<<digitals[i];

    return 0;
}