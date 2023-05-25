#include <bits/stdc++.h>
using namespace std;

int main(){
    double t,colaPer;
    int n,numberOfCups;

    cin>>t>>n;

    colaPer = t / n;
    numberOfCups = 2 * n;

    printf("%.3f\n%d",colaPer,numberOfCups);

}