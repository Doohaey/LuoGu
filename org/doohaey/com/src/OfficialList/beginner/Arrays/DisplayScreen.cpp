#include <bits/stdc++.h>
using namespace std;

vector<string> load(vector<string> displayScreen, int n);
void display(vector<string> displayScreen);
vector<string> loadSingleDigital(vector<string> displayScreen, int i, int digit);

int main(){
    int n;
    cin>>n;
    int rows = 3, cols = 4 * n - 1;
    vector<string> displayScreen(rows, string(cols, '.'));

    displayScreen = load(displayScreen,n);
    display(displayScreen);
}

vector<string> load(vector<string> displayScreen, int n){
    for (int i = 0; i < n; i++) {
        int digit;
        cin >> digit;
        displayScreen = loadSingleDigital(displayScreen, i, digit);
    }
    return displayScreen;
}

void display(vector<string> displayScreen){
    for (const string& row : displayScreen) {
        cout << row << endl;
    }
}

vector<string> loadSingleDigital(vector<string> displayScreen, int i, int digit){
    vector<string> patterns[] = {
        {
            "XXX",
            "X.X",
            "X.X",
            "X.X",
            "XXX"
        },
        {
            "..X",
            "..X",
            "..X",
            "..X",
            "..X"
        },
        {
            "XXX",
            "..X",
            "XXX",
            "X..",
            "XXX"
        },
        {
            "XXX",
            "..X",
            "XXX",
            "..X",
            "XXX"
        },
        {
            "X.X",
            "X.X",
            "XXX",
            "..X",
            "..X"
        },
        {
            "XXX",
            "X..",
            "XXX",
            "..X",
            "XXX"
        },
        {
            "XXX",
            "X..",
            "XXX",
            "X.X",
            "XXX"
        },
        {
            "XXX",
            "..X",
            "..X",
            "..X",
            "..X"
        },
        {
            "XXX",
            "X.X",
            "XXX",
            "X.X",
            "XXX"
        },
        {
            "XXX",
            "X.X",
            "XXX",
            "..X",
            "XXX"
        }
    };

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 3; col++) {
            displayScreen[row][4*i+ col] = patterns[digit][row][col];
        }
    }
    return displayScreen;
}

