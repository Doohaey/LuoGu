#include <bits/stdc++.h>
using namespace std;

int main(){
    int year, month;
    bool isLeapYear;
    cin >> year >> month;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) isLeapYear = true;
    else isLeapYear = false;

    if (month == 1 || month == 3 || month == 5 || month == 7
     || month == 8 || month == 10 || month == 12) cout << "31";
    if (month == 4 || month == 6 || month == 9 || month == 11) cout << "30";
    if (month == 2){
        if (isLeapYear) cout << "29";
        else cout << "28";
    }
}
