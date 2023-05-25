#include <iostream>
#include <vector>

const int MAXN = 100001;
bool bookOfPrime[MAXN];
std::vector<int> primes;

void sieveEuler() {
    std::fill(bookOfPrime, bookOfPrime + MAXN, true);
    bookOfPrime[0] = false;
    bookOfPrime[1] = false;

    for (int i = 2; i < MAXN; ++i) {
        if (bookOfPrime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] < MAXN; ++j) {
            bookOfPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    sieveEuler();

    for (int k = 0; k < n; k++) {
        int nx;
        std::cin >> nx;
        if (bookOfPrime[nx]) {
            std::cout << nx;
            if (k != n - 1) {
                std::cout << " ";
            }
        }
    }
}

