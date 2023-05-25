#include <iostream>
#include <vector>

int n,na,nb,counta = 0,countb = 0;
std::vector<int> cycA,cycB;
int winTable[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};

int main(){
    std::cin>>n>>na>>nb;

    for (int i = 0; i < na; i++){
        int auxA;
        std::cin>>auxA;
        cycA.push_back(auxA);
    }
    for (int j = 0; j < nb; j++){
        int auxB;
        std::cin>>auxB;
        cycB.push_back(auxB);
    }

    for (int k = 0; k < n; k++){
        counta += winTable[cycA[k % na]][cycB[k % nb]];
        countb += winTable[cycB[k % nb]][cycA[k % na]];
    }

    std::cout<<counta<<" "<<countb;
}