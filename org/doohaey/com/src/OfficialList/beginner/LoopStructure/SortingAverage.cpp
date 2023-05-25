#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,numberOfA,numberOfB;
    double averageA,averageB;
    cin>>n>>k;
    numberOfA = n / k;
    numberOfB = n - numberOfA;
    int totalA = 0,totalB = 0;
    for(int i = 1; i <= n; i++){
        if (i % k == 0) totalA += i;
        else totalB += i;
    }
    averageA = totalA / (double)numberOfA;
    averageB = totalB / (double)numberOfB;
    cout<<fixed<<setprecision(1)<<averageA<<" ";
    cout<<fixed<<setprecision(1)<<averageB;
}