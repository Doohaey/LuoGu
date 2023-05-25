#include <iostream>
#include <climits>
#include <cmath>

int n,ts = 1,tb = 0,min = INT_MAX;

struct Ingredient{
    int s;
    int b;
};

Ingredient ig[20];

void deepFirstSearch(int x){
    if (x < n){
        deepFirstSearch(x+1);
        ts *= ig[x].s;
        tb += ig[x].b;
        deepFirstSearch(x+1);
    }
    else if (ts != 1 && tb != 0){
        min = std::abs(ts - tb) < min ? std::abs(ts - tb) : min;
    }
}

int main(){
    std::cin>>n;
    for (int i = 0; i < n; i++){
        std::cin>>ig[i].s>>ig[i].b;
    }

    deepFirstSearch(0);
    std::cout<<min;
}
