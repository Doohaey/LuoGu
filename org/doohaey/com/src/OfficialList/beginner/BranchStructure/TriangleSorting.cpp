#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int arr[3] {a, b, c};
    sort(arr, arr + 3);

    // 能不能构成三角形
    if (arr[0] + arr[1] <= arr[2]) {
        cout << "Not triangle";
    } else {
        if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
            cout << "Right triangle" << endl;
        } else if (arr[0] * arr[0] + arr[1] * arr[1] > arr[2] * arr[2]) {
            cout << "Acute triangle" << endl;
        } else {
            cout << "Obtuse triangle" << endl;
        }

        if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]) {
            cout << "Isosceles triangle" << endl;
        }
        
        if (arr[0] == arr[1] && arr[0] == arr[2]) {
            cout << "Equilateral triangle" << endl;
        }
    }

    return 0;
}
