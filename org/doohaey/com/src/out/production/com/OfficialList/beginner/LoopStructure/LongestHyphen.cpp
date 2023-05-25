#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, nx, nxb, count = 1, longestCount = 1;
    cin >> n;

    if (n > 0) cin >> nxb;

    for (int i = 1; i < n; i++) {
        cin >> nx;
        if (nxb == nx - 1) {
            count++;
        } else {
            if (count > longestCount) {
                longestCount = count;
            }
            count = 1;
        }
        nxb = nx;
    }

    if (count > longestCount) {
        longestCount = count;
    }

    cout << longestCount;
}
