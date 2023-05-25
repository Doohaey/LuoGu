#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> readSquare(int n);
int searchOperateType(vector<vector<char>> squareInitialized, vector<vector<char>> squareToMatch, int n);
vector<vector<char>> transformOperation(vector<vector<char>> squareInitialized, int j, int n);
bool areVectorsEqual(const vector<vector<char>>& vec1, const vector<vector<char>>& vec2);
vector<vector<char>> rotateNinety(vector<vector<char>> squareInitialized, int n);
vector<vector<char>> flip(vector<vector<char>> squareInitialized, int n);

int main(){
    int n;
    cin>>n;

    vector<vector<char>> squareToMatch = readSquare(n);
    vector<vector<char>> squareInitialized = readSquare(n);
    
    int operateType = searchOperateType(squareInitialized, squareToMatch, n); 
    cout << operateType << endl;
}

vector<vector<char>> readSquare(int n){
    vector<vector<char>> square;
    for (int i = 0; i < n; i++){
        vector<char> row;
        for (int j = 0; j < n; j++){
            char x;
            cin>>x;
            row.push_back(x);
        }
        square.push_back(row);
    }
    return square;
}

int searchOperateType(vector<vector<char>> squareInitialized, vector<vector<char>> squareToMatch, int n){
    for (int j = 1; j <= 8; j++){
        vector<vector<char>> square = transformOperation(squareInitialized, j, n);
        if (areVectorsEqual(square, squareToMatch)) {
            if (j == 7 || j == 8) {
                return 5;
            }
            return j;
        }
    }

    return 7;
}


vector<vector<char>> transformOperation(vector<vector<char>> squareInitialized, int j, int n){
    vector<vector<char>> square;
    switch (j)
    {
    case 1:
        square = rotateNinety(squareInitialized,n);
        break;
    case 2:
        square = rotateNinety(squareInitialized,n);
        square = rotateNinety(square,n);
        break;
    case 3:
        square = rotateNinety(squareInitialized,n);
        square = rotateNinety(square,n);
        square = rotateNinety(square,n);
        break;
    case 4:
        square = flip(squareInitialized,n);
        break;
    case 5:
        square = flip(squareInitialized,n);
        square = rotateNinety(square,n);
        break;
    case 6:
        square = squareInitialized;
        break;
    case 7:
        square = flip(squareInitialized,n);
        square = rotateNinety(square,n);
        square = rotateNinety(square,n);
        break;
    case 8:
        square = flip(squareInitialized,n);
        square = rotateNinety(square,n);
        square = rotateNinety(square,n);
        square = rotateNinety(square,n);
        break;
    default:
        break;
    }
    return square;
}


bool areVectorsEqual(const vector<vector<char>>& vec1, const vector<vector<char>>& vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }
    
    for (size_t i = 0; i < vec1.size(); ++i) {
        if (vec1[i].size() != vec2[i].size()) {
            return false;
        }
        if (!equal(vec1[i].begin(), vec1[i].end(), vec2[i].begin())) {
            return false;
        }
    }
    
    return true;
}

vector<vector<char>> rotateNinety(vector<vector<char>> squareInitialized, int n){
    vector<vector<char>> square(n, vector<char>(n));
    for (int k = 0; k < n; k++){
        for (int l = 0; l < n; l++){
            square[n - l - 1][k] = squareInitialized[k][l];
        }
    }
    return square;
}

vector<vector<char>> flip(vector<vector<char>> squareInitialized, int n){
    vector<vector<char>> square(n, vector<char>(n));
    for (int k = 0; k < n; k++){
        for (int l = 0; l < n / 2; l++){
            swap(squareInitialized[k][l], squareInitialized[k][n - l - 1]);
        }
    }
    square = squareInitialized;
    return square;
}
