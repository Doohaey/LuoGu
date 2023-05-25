#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,number,count = 0;;
    cin>>n;
    
    for(int i = n; i > 0; i--){
        for(int j = 0; j < i; j++){
            count++;
            cout<<setw(2)<<setfill('0')<<count;
        }
        cout<<"\n";
    }
}