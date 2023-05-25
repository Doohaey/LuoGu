#include <bits/stdc++.h>
using namespace std;

#define YUAN_JIAO_CONVERSION 10
#define PRICE_OF_GELPEN_IN_JIAO 19

int main(){
    int a,b,c;
    cin>>a>>b;
    c = (a * YUAN_JIAO_CONVERSION + b) / PRICE_OF_GELPEN_IN_JIAO;
    cout<<c;
}