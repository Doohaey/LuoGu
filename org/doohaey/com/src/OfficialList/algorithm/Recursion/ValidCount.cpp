#include <iostream>

int n;
int kinds[1001] = {0};

void count(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i / 2; j++){
            kinds[i] += kinds[j];
        }
        kinds[i]++;
    }
}

int main(){
    std::cin >> n;
    count();
    std::cout<<kinds[n];
}