#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    if(a % 2 == 0) a++;

    for (int i = a; i <= b; i += 2) {
        bool isPalindrome = true, isPrime = true;
        int aux = i;
        vector<int> digits;

        while (aux > 0) {
            digits.push_back(aux % 10);
            aux /= 10;
        }
        for (int j = 0; j < digits.size() / 2; j++) {
            if (digits.at(j) != digits.at(digits.size() - j - 1)) {
                isPalindrome = false;
                break;
            }
        }
        if (!isPalindrome) continue;

        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime && isPalindrome) cout << i << endl;
    }
    
    return 0;
}