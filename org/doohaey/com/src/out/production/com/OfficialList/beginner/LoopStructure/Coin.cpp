#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,coins = 0;
    cin>>k;

    for (int i = 1; i <= k; i++){
        int n;
        if (i != 1){
            for (int j = 1; j * (j + 1) / 2 < i; j++){
                n = j;
            }
        }else n = 0;
        coins += n + 1;
    }
    cout<<coins;
}