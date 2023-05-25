#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,n1,n2,n3,p1,p2,p3;
    cin>>n>>n1>>p1>>n2>>p2>>n3>>p3;
    
    int minCost = INT_MAX;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                if(i * n1 + j * n2 + k * n3 >= n){
                    minCost = min(minCost, i * p1 + j * p2 + k * p3);
                }
            }
        }
    }

    cout << minCost << endl;
}
