#include <iostream>
using namespace std;

const int MONTHLY_INCOME = 300;

int main() {
    int accountBalance = 0, monthlyOutcome;
    double moneySaved = 0;

    for (int i = 1; i <= 12; i++) {
        cin >> monthlyOutcome;
        accountBalance += MONTHLY_INCOME - monthlyOutcome;
        if (accountBalance < 0) {
            cout << "-" << i << endl;
            return 0;
        } else if (accountBalance >= 100) {
            moneySaved += 100 * (accountBalance / 100);
            accountBalance %= 100;
            if (i == 12) moneySaved *= 1.2;
        }
    }

    cout << accountBalance + moneySaved << endl;
    return 0;
}
