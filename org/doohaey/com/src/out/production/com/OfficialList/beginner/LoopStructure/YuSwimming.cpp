#include <bits/stdc++.h>
using namespace std;

#define LAPSE_RATE 0.98

int main(){
    double s,sRealize = 0,sPer = 2;
    int steps;
    cin>>s;

    for (steps = 0; sRealize < s; steps++){
        sRealize += sPer;
        sPer *= LAPSE_RATE;
    }

    cout<<steps;
}