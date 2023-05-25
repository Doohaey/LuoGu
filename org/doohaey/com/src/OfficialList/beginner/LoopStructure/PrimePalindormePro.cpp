#include <bits/stdc++.h>
using namespace std;

vector<bool> sieveLinear(int n);
bool isPalindromes(int n);

int main() {
    int lowerBound, upperBound;
    cin >> lowerBound >> upperBound;

    if (lowerBound % 2 == 0) lowerBound++;
    if (upperBound >= 100000000) upperBound = 9999999;

    vector<bool> primes = sieveLinear(upperBound);

    for (int i = lowerBound; i <= upperBound; i += 2) {
        if (primes[i] && isPalindromes(i)) {
            cout << i << endl;
        }
    }

    return 0;
}

vector<bool> sieveLinear(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break; 
        }

    return isPrime;
    }
}

bool isPalindromes(int n) {
    int reversedNumber = 0, originalNumber = n, remainder;

    while (n != 0) {
        remainder = n % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        n /= 10;
    }

    return originalNumber == reversedNumber;
}

