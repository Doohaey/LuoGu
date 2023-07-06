#include <iostream>
#include <cstring>

int num;
char alphabet[100][100];
bool boole[100][100];

const int dx[] = { 1, 1, 1, 0, 0, -1,-1,-1}; 
const int dy[] = { 1, 0, -1, 1, -1, 0, 1, -1};
const std::string to_search = " yizhong";

void operation(int k,int x, int y){
    int left = 7;
    while (left){
        left--;
        boole[x][y] = true;
        x -= dx[k];
        y -= dy[k];
    }
}

void deepFirstSearch(int i, int j){
    for (int k = 0; k < 8; k++){
        int pos_x = i, pos_y = j, seq = 1;
        while (seq < 7){
            seq++;
            pos_x += dx[k];
            pos_y += dy[k];

            if (pos_x < 0 || pos_y < 0 || pos_x >= num || pos_y >= num){
                break;
            }
            if (alphabet[pos_x][pos_y] != to_search[seq]){
                break;
            }

            if (seq == 7){
                operation(k, pos_x, pos_y);
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::cin >> num;
    memset(boole, false, sizeof(boole));
    
    for (int i = 0; i < num; i++){
        for (int j = 0; j < num; j++){
            std::cin >> alphabet[i][j];
        }
    }

    for (int i = 0; i < num; i++){
        for (int j = 0; j < num; j++){
            if (alphabet[i][j] == 'y'){
                deepFirstSearch(i,j);
            }
        }
    }

    for (int i = 0; i < num; i++){
        for (int j = 0; j < num; j++){
            std::cout << ((boole[i][j]) ? alphabet[i][j] : '*');
        }
        std::cout << std::endl;
    }

    return 0;
}
