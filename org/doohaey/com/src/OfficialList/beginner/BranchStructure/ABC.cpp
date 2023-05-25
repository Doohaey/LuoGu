#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, z;
    char X, Y, Z;
    cin >> x >> y >> z >> X >> Y >> Z;

    vector<int> numbers {x, y, z};
    sort(numbers.begin(), numbers.end());

    map<char, int> charToNum;
    charToNum['A'] = numbers[0];
    charToNum['B'] = numbers[1];
    charToNum['C'] = numbers[2];

    cout << charToNum[X] << " " << charToNum[Y] << " " << charToNum[Z];

    return 0;
}

