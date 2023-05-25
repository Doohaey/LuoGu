#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,count = 0;
    cin>>n;
    int nx[n][3];

    for (int i = 0; i < n; i++) cin>>nx[i][0]>>nx[i][1]>>nx[i][2];

    for (int j = 0; j < n; j++){
        int sumj = nx[j][0] + nx[j][1] + nx[j][2];
        for (int k = j + 1; k < n; k++){
            int sumk = nx[k][0] + nx[k][1] + nx[k][2];
            bool sumScoreGap = abs(sumj - sumk) <= 10;
            bool chineseScoreGap = abs(nx[j][0] - nx[k][0]) <= 5; 
            bool mathScoreGap = abs(nx[j][1] - nx[k][1]) <= 5;
            bool englishScoreGap = abs(nx[j][2] - nx[k][2]) <= 5;
            if(sumScoreGap && chineseScoreGap && mathScoreGap && englishScoreGap)  count++;
        }
    }

    cout<<count; 
}