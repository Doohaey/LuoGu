#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b);

int main(){
    int a,b,c,numerator,reducedNumerator,denominator,reducedDenominator,gcdResult;
    cin>>a>>b>>c;
    int arr[3] {a,b,c};
    sort(arr,arr + 3);

    denominator = arr[2];
    numerator = arr[0];
    gcdResult = gcd(numerator,denominator);
    reducedDenominator = denominator / gcdResult;
    reducedNumerator = numerator / gcdResult;

    cout<<reducedNumerator<<"/"<<reducedDenominator<<endl;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}