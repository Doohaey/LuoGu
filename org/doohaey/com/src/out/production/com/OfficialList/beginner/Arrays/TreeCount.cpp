#include <bits/stdc++.h>
using namespace std;

int main(){
    int length,numberOfAreas,count = 0;
    cin>>length>>numberOfAreas;
    
    vector<bool> area(length + 1,true);

    for(int i = 0; i < numberOfAreas; i++){
        int lowerBound,upperBound;
        cin>>lowerBound>>upperBound;
        for (int j = lowerBound; j <= upperBound; j++) area[j] = false;
    }

    for (int k = 0; k <= length; k++) if (area[k]) count++;

    cout<<count;

    return 0;
}
