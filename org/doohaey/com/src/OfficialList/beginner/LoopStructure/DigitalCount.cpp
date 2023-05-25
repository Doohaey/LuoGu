#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,count = 0;
    cin>>n>>x;

    for(int i = 1; i <= n; i++){
        int j = i;
        while(j > 0){
            if(j % 10 == x) count++;
            j /= 10;
        }
    }

    cout<<count;   
}