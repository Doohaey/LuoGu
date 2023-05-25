#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int nx[n];

    for (int i = 0; i < n; i++) cin>>nx[i];

    for (int j = 0; j < n; j++){
        int count = 0;
        for (int k = 0; k < j; k++) if (nx[j] > nx[k]) count++;
        cout<<count<<" ";
    }
}