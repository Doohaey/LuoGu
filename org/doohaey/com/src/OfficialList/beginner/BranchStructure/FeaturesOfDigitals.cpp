#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    bool isEven,isInArea;
    int A,Uim,Eight,Sister;
    cin>>x;

    if(x % 2 == 0) isEven = true;
    else isEven = false;
    if(x > 4 && x <= 12) isInArea = true;
    else isInArea = false;

    A = (isEven && isInArea) ? 1 : 0;
    Uim = (isEven || isInArea) ? 1 : 0;
    Eight = (isEven ^ isInArea) ? 1 : 0;
    Sister = (!isEven && !isInArea) ? 1 : 0;

    cout<<A<<" "<<Uim<<" "<<Eight<<" "<<Sister<<endl;
}
