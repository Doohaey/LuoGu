#include <bits/stdc++.h>
using namespace std;

#define MINUTE_HOUR_CONVERSION 60

int main(){
    int a,b,c,d,e,f,time;
    cin>>a>>b>>c>>d;
    time = c * MINUTE_HOUR_CONVERSION + d - (a * MINUTE_HOUR_CONVERSION + b);
    e = time / 60;
    f = time % 60;
    cout<<e<<" "<<f;
}