#include <iostream>
#include <cmath>
#include <algorithm>

int main(){
    int n;
    std::cin>>n;

    int nx[1000],dif[999] = {0};
    std::cin>>nx[0];
    for (int i = 1; i < n; i++){
        std::cin>>nx[i];
        dif[i - 1] = std::abs(nx[i] - nx[i - 1]);
    }
    std::sort(dif,dif+n-1);

    for(int i = 0; i < n - 1; i++){
        if(dif[i] != i + 1){
            std::cout<<"Not jolly"<<std::endl;
            return 0;
        }
    }
    std::cout<<"Jolly"<<std::endl;
    return 0;
}