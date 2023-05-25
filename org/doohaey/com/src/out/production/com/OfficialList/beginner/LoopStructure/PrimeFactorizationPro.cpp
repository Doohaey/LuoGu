#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n);

int main() {
    int n, p = 0;
    cin >> n;

    for (int k = 2; k * k <= n; k++) {
        if (isPrime(k) && (n % k == 0)) {
            int q = n / k;
            if (k > p) p = k;
            if (q > p) p = q;
        }
    }

    cout << p;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}
