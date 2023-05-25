#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,picket = INT_MAX;
    cin>>n;

    int ax[n];
    for (int i = 0; i < n; i++) {
        cin>>ax[i];
        if (ax[i] < picket) picket = ax[i];
    }

    cout<<picket;
}
