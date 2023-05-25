#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,day = 1,dailyLength;
    cin>>a;
    dailyLength = a;

    while (dailyLength > 1)
    {
        day++;
        dailyLength /= 2;
    }

    cout<<day;
}