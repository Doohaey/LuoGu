#include <iostream>
#include <vector>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> sweeperArea(n, std::vector<char>(m));
    std::vector<std::vector<int>> countMine(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            std::cin >> sweeperArea[i][j];
            if (sweeperArea[i][j] == '*') countMine[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (sweeperArea[i][j] == '*'){
                for (int l = i - 1; l <= i + 1; l++){
                    for (int k = j - 1; k <= j + 1; k++){
                        if (l >= 0 && k >= 0 && l < n && k < m && countMine[l][k] != -1) {
                            countMine[l][k]++;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (countMine[i][j] == -1) {
                std::cout << '*';
            } else {
                std::cout << countMine[i][j];
            }
        }
        std::cout << std::endl;
    }
}
