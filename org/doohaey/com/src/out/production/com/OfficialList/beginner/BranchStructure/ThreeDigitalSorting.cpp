#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, aux = 0;
    cin >> a >> b >> c;

    if (a > b) {
        aux = a;
        a = b;
        b = aux;
    }
    if (a > c) {
        aux = a;
        a = c;
        c = aux;
    }
    if (b > c) {
        aux = b;
        b = c;
        c = aux;
    }

    cout << a << " " << b << " " << c << endl;
}
