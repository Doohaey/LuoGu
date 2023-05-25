#include <iostream>

int n,k,count = 0;
int table[20];

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void digitalSelection(int pro, int pos, int sum){
    if (pos != -1){
        sum += table[pos];
    }
    if (pro < k){
        for (int i = pos + 1; i <= n - k + pro; i++){
            digitalSelection(pro+1,i,sum);
        }
    }else if (pro == k){
        if (isPrime(sum)) count++;
    }
}

int main(){
    std::cin>>n>>k;
    for (int i = 0; i < n; i++) std::cin>>table[i];
    digitalSelection(0,-1,0);
    std::cout<<count;
}