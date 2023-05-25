#include<bits/stdc++.h>
using namespace std;

vector<int> addToWinningCount(vector<int> winningNumbers, vector<int> winningCount);

int main(){
    int n;
    vector<int> winningNumbers;
    vector<int> winningCount(7,0);
    cin>>n;

    for (int i = 0; i < 7; i++) {
        int aux;
        cin>>aux;
        winningNumbers.push_back(aux);
    }

    for (int j = 0; j < n; j++) winningCount = addToWinningCount(winningNumbers,winningCount);

    for (int a = 0; a < 7; a++) cout<<winningCount.at(a)<<" ";
}

vector<int> addToWinningCount(vector<int> winningNumbers, vector<int> winningCount){
    int count = 0;
    for (int k = 0; k < 7; k++) {
        int aux;
        cin>>aux;
        for (int l = 0; l < 7; l++){
            if (aux == winningNumbers.at(l)) count++;
        }
    }

    if (count != 0) winningCount.at(7 - count)++;
    
    return winningCount; 
}