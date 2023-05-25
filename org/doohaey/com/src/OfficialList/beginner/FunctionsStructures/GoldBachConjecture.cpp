#include <iostream>
#include <vector>

bool isPrime[10001];
std::vector<int> primes;

void initializeIsPrimeArray() {
    for (int i = 0; i < 10001; i++) {
        isPrime[i] = true;
    }
}

void sieveLinear(int n){
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i < n; i++){
        if (isPrime[i]){
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++){
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(){
    int evenNumber,prime1,prime2;
    std::cin>>evenNumber;

    initializeIsPrimeArray();
    sieveLinear(evenNumber);

    for (int j = 4; j <= evenNumber; j += 2){
        for (int k = 0; k < primes.size() && primes[k] <= j / 2; k++){
            if (isPrime[j - primes[k]]) {
                std::cout<<j<<"="<<primes[k]<<"+"<<j-primes[k]<<std::endl;
                break;
            }
        }
    }
}