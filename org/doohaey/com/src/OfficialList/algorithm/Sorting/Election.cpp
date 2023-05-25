#include <iostream>
#include <algorithm>

int main(){
    int n,m;
    std::cin>>n>>m;
    int ballots[m];
    for (int i = 0; i < m; i++){
        std::cin>>ballots[i];
    }
    std::sort(ballots,ballots+m);
    for (int i = 0; i < m; i++){
        std::cout<<ballots[i];
        if (i != m - 1) std::cout<<" ";
    }
}