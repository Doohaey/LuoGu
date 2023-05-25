#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,n,total = 0;
    cin>>x>>n;

    for(int i = 1; i <= n; i++) if (((i + x - 1) % 7) != 6 && ((i + x - 1)) % 7 != 0) total += 250;

    cout<<total;
    return 0;
}