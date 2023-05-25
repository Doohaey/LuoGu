#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> stepsRecord;

    stepsRecord.push_back(n);
    while (n > 1){
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        stepsRecord.push_back(n);
    }

    for (int i = stepsRecord.size() - 1; i >= 0; i--) cout<<stepsRecord[i]<<" ";

    return 0;
}