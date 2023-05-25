#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,nRead,max = 0,min = INT_MAX,sum = 0;
    cin>>n;
    vector<int> nx;

    for (int i = 0; i < n; i++){
        cin>>nRead;
        nx.push_back(nRead);

        if (nRead < min) min = nRead;
        if (nRead > max) max = nRead;
    }

    for (int j = 0; j < n; j++){
        if (nx[j] == max) {
            nx.erase(nx.begin() + j);
            break;
        }
    }

    for (int k = 0; k < n - 1; k++){
        if (nx[k] == min) {
            nx.erase(nx.begin() + k);
            break;
        }
    }

    for (int l = 0; l < n - 2; l++) sum += nx[l];

    double average = (double)sum / (n - 2);
    cout<<fixed<<setprecision(2)<<average;

    return 0;
}
