#include <iostream>
#include <algorithm>

int main(){
    int n,count = 1;
    std::cin>>n;
    int nx[n];
    for (int i = 0; i < n; i++){
        std::cin>>nx[i];
    }
    std::sort(nx,nx+n);
    for (int j = 1; j < n; j++){
        if (nx[j] != nx[j-1]) count++;
    }
    std::cout<<count<<std::endl<<nx[0];
    if (n != 1) std::cout<<" ";
    for (int k = 1; k < n; k++){
        if (nx[k] != nx[k-1]) {
            std::cout<<nx[k];
            if (k != n - 1) std::cout<<" ";
        }
    }   
}