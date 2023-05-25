#include<bits/stdc++.h>
using namespace std;

int main(){
    int L,sumIn = 0;
    cin>>L;
    vector<int> primePocket;

    for (int i = 2; sumIn + i <= L; i++){
        bool isPrime = true;
        for (int j = 2; j <= pow(i,1.0/2); j++){
            if (i % j == 0){
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primePocket.push_back(i);
            sumIn += i;
        }
    }

    for(int k = 0; k < primePocket.size(); k++) cout<<primePocket.at(k)<<endl;
    cout<<primePocket.size();
}