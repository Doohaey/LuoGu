#include <bits/stdc++.h>
using namespace std;

vector<bool> sieveEratosthenes(int n);

int main() {
    int n, p = 0;
    cin >> n;
    vector<bool> isPrime = sieveEratosthenes(n);

    for (int k = 1; k < n; k++) {
        if (isPrime[k] && (n % k == 0) && (k > p)) p = k;
    }

    cout << p;
}

vector<bool> sieveEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}
