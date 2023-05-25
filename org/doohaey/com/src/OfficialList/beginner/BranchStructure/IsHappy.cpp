#include<bits/stdc++.h>
using namespace std;

int main(){
    int a1,a2,a3,a4,a5,a6,a7,b1,b2,b3,b4,b5,b6,b7;
    int dayUnhappy = 0,largestUnhappyLevel = 0;
    cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4>>a5>>b5>>a6>>b6>>a7>>b7;
    int a[7] = {a1,a2,a3,a4,a5,a6,a7};
    int b[7] = {b1,b2,b3,b4,b5,b6,b7};

    for(int i = 0; i < 7; i++){
        if (a[i] + b[i] > 8 && a[i] + b[i] > largestUnhappyLevel){
            dayUnhappy = i + 1;
            largestUnhappyLevel = a[i] + b[i];
        }
    } 

    cout<<dayUnhappy;
}