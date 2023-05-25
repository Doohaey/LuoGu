#include <bits/stdc++.h>
using namespace std;

#define PI 3.141593
#define radius 5

int main(){
    int T;
    cin >> T;
    switch (T)
    {
    case 1:
        cout << "I love Luogu!";
        break;
    case 2:
        int total2, A2, Uim2, B2, partTotal2;
        total2 = 10;
        A2 = 2;
        Uim2 = 4;
        partTotal2 = A2 + Uim2;
        B2 = total2 - partTotal2;
        cout << partTotal2 << " " << B2;
        break;
    case 3:
        int total3, number3, per3, left3,out3;
        total3 = 14;
        number3 = 4;
        per3 = total3 / number3;
        left3 = total3 % number3;
        out3 = total3 - left3;
        cout << per3 <<endl<<out3<<endl<<left3;
        break;
    case 4:
        cout<<fixed<<setprecision(3)<<1.0*500/3;
        break;
    case 5:
        int ALength5, ASpeed5, BLength5, BSpeed5, totalLength5, totalSpeed5, timeCost5;
        ALength5 = 260;
        BLength5 = 220;
        ASpeed5 = 12;
        BSpeed5 = 20;
        totalLength5 = ALength5 + BLength5;
        totalSpeed5 = ASpeed5 + BSpeed5;
        timeCost5 = totalLength5 / totalSpeed5;
        cout << timeCost5;
        break;
    case 6:
        cout << sqrt(117);
        break;
    case 7:
        int initial7, save7, cost7, A7, B7, C7;
        initial7 = 100;
        save7 = 10;
        cost7 = 20;
        A7 = initial7 + save7;
        cout << A7 << endl;
        B7 = A7 - cost7;
        cout << B7 << endl;
        C7 = 0;
        cout << C7;
        break;
    case 8:
        double circumference, area, volume;
        circumference = 2 * PI * radius;
        area = PI * radius * radius;
        volume = (4.0 / 3) * PI * radius * radius * radius;
        cout << circumference << endl << area << endl << volume << endl;
        break;
    case 9:
        int initialNumber9, recallOne9, recallTwo9, recallThree9;
        initialNumber9 = 1;
        recallOne9 = (initialNumber9 + 1) * 2;
        recallTwo9 = (recallOne9 + 1) * 2;
        recallThree9 = (recallTwo9 + 1) * 2;
        cout << recallThree9;
        break;
    case 10:
        int numberA10, numberB10, timeA10, timeB10, timeToSolve10, numberOfAnswer10, initialWork10, deltaWorkSpeed10;
        numberA10 = 8;
        numberB10 = 10;
        timeA10 = 30;
        timeB10 = 6;
        timeToSolve10 = 10;
        deltaWorkSpeed10 = ((timeB10 * numberB10) - (timeA10 * numberA10)) / (timeB10 - timeA10);
        initialWork10 = (timeB10 * numberB10) - (deltaWorkSpeed10 * timeB10);
        numberOfAnswer10 = 1 + (initialWork10 + (deltaWorkSpeed10 * timeToSolve10)) / timeToSolve10;
        cout << numberOfAnswer10 << endl;
        break;
    case 11:
        cout << (100.0 / (8 - 5)) << endl;
        break;
    case 12:
        int numberOfM12;
        char alphabetUnknown12;
        numberOfM12 = (int) ('M' - 'A' + 1);
        alphabetUnknown12 = (char) ('A' + 18 - 1);
        cout << numberOfM12 << endl << alphabetUnknown12 << endl;
        break;
    case 13:
        int r1, r2, l;
        r1 = 4;
        r2 = 10;
        l = (int)(pow((4.0 / 3) * PI * (r1 * r1 * r1 + r2 * r2 * r2), 1.0 / 3));
        cout << l << endl;
        break;
    case 14:
        double a = 1, b = -120, c = 3500;
        double delta = b * b - 4 * a * c;
        double x = (-b - sqrt(delta)) / (2 * a);
        x = round(x);
        cout << fixed << setprecision(0) << x << endl;
        break;
    }
}

    


