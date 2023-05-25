#include <bits/stdc++.h>
using namespace std;

#define HEIGHT_OF_BENCH 30

int main(){
    int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,height,count = 0;;
    cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>height;
    vector<int> apples {a1,a2,a3,a4,a5,a6,a7,a8,a9,a10};

    for(int i = 0; i < 10; i++){
        if (height + HEIGHT_OF_BENCH >= apples[i]) count ++;
    }

    cout<<count;
}