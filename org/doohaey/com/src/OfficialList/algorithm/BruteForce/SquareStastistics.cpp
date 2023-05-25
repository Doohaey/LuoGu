#include <iostream>
#include <algorithm>
int n,m;
long long countSquare = 0,countRectangle = 0;

void countSqr(int a){
    countSquare += (n - a + 1) * (m - a + 1);
}

void countRec(int a, int b){
    if (a != b){
        countRectangle += (n - a + 1) * (m - b + 1);
    }
}

int main(){
    std::cin>>n>>m;
    for (int i = 1; i <= std::min(n,m); i++){
        countSqr(i);
    }
    for (int j = 1; j <= n; j++){
        for (int k = 1; k <= m; k++){
            countRec(j,k);
        }
    }

    std::cout<<countSquare<<" "<<countRectangle;
}