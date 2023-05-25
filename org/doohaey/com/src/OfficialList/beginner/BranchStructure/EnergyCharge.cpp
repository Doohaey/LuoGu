#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    double p1 = 0.4463,p2 = 0.4663,p3 = 0.5663,pTotal;
    cin>>x;

    if (x <= 150) pTotal = 0.4463 * x;
    else if (x <= 400) pTotal = 0.4463 * 150 + 0.4663 * (x - 150);
    else if (x > 400) pTotal = 0.4463 * 150 + 0.4663 * 250 + 0.5663 * (x - 400);
    
    cout<<fixed<<setprecision(1)<<pTotal;
}