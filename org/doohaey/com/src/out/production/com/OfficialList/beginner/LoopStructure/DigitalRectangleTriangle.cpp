#include <bits/stdc++.h>
using namespace std;

void printRec(int n);
void printTri(int n);

int main(){
    int n;
    cin>>n;
    
    printRec(n);
    cout<<"\n";
    printTri(n);
}

void printRec(int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            count++;
            cout<<setw(2)<<setfill('0')<<count;
        }
        cout<<"\n";
    }
}

void printTri(int n){
    int count = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < n - i; j++) cout<<"  ";
        for (int k = 0; k < i ; k++) {
            count++;
            cout<<setw(2)<<setfill('0')<<count;
        }
        cout<<"\n";
    }
}