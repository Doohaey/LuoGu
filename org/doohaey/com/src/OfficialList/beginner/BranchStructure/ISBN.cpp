#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    vector<int> nums;
    for (char c : input) {
        if (isdigit(c)) {
            nums.push_back(c - '0');
        } else if (c == 'X' || c == 'x') {
            nums.push_back(10);
        }
    }

    int a = nums[0], b1 = nums[1], b2 = nums[2], b3 = nums[3], c1 = nums[4], c2 = nums[5], c3 = nums[6], c4 = nums[7], c5 = nums[8], check = nums[9];

    int rightCheck = a * 1 + b1 * 2 + b2 * 3 + b3 * 4 + c1 * 5 + c2 * 6 + c3 * 7 + c4 * 8 + c5 * 9;
    rightCheck %= 11;

    if (check == rightCheck)
        cout << "Right";
    else
        if(rightCheck != 10) cout << a << "-" << b1 << b2 << b3 << "-" << c1 << c2 << c3 << c4 << c5 << "-" << rightCheck;
        else cout << a << "-" << b1 << b2 << b3 << "-" << c1 << c2 << c3 << c4 << c5 << "-X";
    return 0;
}
