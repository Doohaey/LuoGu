#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,nx,max = 0,min = INT_MAX,range;
    cin>>n;

    for (int i = 0; i < n; i++){
        cin>>nx;
        if (nx > max) max = nx;
        if (nx < min) min = nx;
    }

    range = max - min;
    cout<<range;
}