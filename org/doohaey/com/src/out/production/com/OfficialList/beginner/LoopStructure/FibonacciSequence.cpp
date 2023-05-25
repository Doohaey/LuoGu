#include <bits/stdc++.h>
using namespace std;

double fibonacci(int n);

int main(){
    int n;
    double output;
    cin>>n;
    output = fibonacci(n);
    cout<<fixed<<setprecision(2)<<output;
}

double fibonacci(int n){
    double fibonacci;
    fibonacci = (pow(((1 + sqrt(5)) / 2),n) - pow(((1 - sqrt(5)) / 2),n)) / sqrt(5);
    return fibonacci;
}