#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n;
    int rec[10] = {0};
    cin>>m>>n;

    for (int i = m; i <= n; i++){
        int temp = i;
        while (temp > 0){
            rec[temp % 10]++;
            temp /= 10;
        }
    }

    for (int j = 0; j < 10; j++) cout<<rec[j]<<" ";

    return 0;
}