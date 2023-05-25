#include <iostream>
#include <algorithm>

int main(){
    int n,kth;
    scanf("%d%d",&n,&kth);
    int digitals[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&digitals[i]);
    }
    std::nth_element(digitals,digitals+kth,digitals+n);
    printf("%d",digitals[kth]);
}