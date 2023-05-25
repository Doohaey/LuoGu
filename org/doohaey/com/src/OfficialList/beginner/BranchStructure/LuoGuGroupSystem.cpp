#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,localTime,luoguTime;
    cin>>n;

    localTime = 5 * n;
    luoguTime = 11 + 3 * n;

    if(localTime < luoguTime) cout<<"Local";
    else cout<<"Luogu";
}