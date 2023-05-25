#include <bits/stdc++.h>
using namespace std;

#define KILO_TRANS 1000
#define PI 3.14
#define WATER_TO_DRINK 20

int main(){
    int h,r,numberOfBUCKETS;
    double auxNumber;
    cin>>h>>r;
    auxNumber = WATER_TO_DRINK / (h * r * r * PI / KILO_TRANS);
    numberOfBUCKETS = ceil(auxNumber);
    cout<<numberOfBUCKETS;
}