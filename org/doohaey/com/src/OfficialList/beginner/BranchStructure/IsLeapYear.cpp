#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,output;
    bool isLeapYear;
    cin>>x;

    if((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0)) isLeapYear = true;
    else isLeapYear = false;

    output = (isLeapYear) ? 1:0;
    cout<<output;
}