#include<bits/stdc++.h>
using namespace std;

int main(){
    int moneyToRaise,x,k;
    cin>>moneyToRaise;
    int pos[2] {0,moneyToRaise / 1092};

    for (x = 1; x * 364 < moneyToRaise && x <= 100; x++){
        for (k = 1; k * 1092 < moneyToRaise; k++){
            if (x * 364 + k * 1092 == moneyToRaise && x > pos[0]){
                pos[0] = x;
                pos[1] = k;  
            } 
        }
    }

    cout<<pos[0]<<endl<<pos[1];

    return 0;
}