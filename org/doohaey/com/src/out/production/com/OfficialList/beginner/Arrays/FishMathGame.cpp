#include <bits/stdc++.h>
using namespace std;

int main(){
    int nx;
    vector<int> arrayToReverse;
    
    cin>>nx;
    for (int i = 0; nx != 0; i++) {
        arrayToReverse.push_back(nx);
        cin>>nx;
    }

    for (int j = arrayToReverse.size() - 1; j >= 0; j--) cout<<arrayToReverse[j]<<" ";

    return 0;
}