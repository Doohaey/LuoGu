#include <iostream>
#include <iomanip>
#include <cstring>
#include <queue>

int length, width, horse_x, horse_y;
int chessBoard[401][401];
bool visited[401][401];

const int dx[8] = {2, -2, 2, -2, -1, 1, -1, 1};
const int dy[8] = {1, 1, -1, -1, 2, 2, -2, -2};

bool check(int x, int y) {
    return x >= 1 && y >= 1 && x <= length && y <= width && !visited[x][y];
}

void breadthFirstSearch(int x, int y) {
    std::queue<std::pair<std::pair<int, int>, int>> queue;
    queue.push({{x, y}, 0});
    visited[x][y] = true;

    while (!queue.empty()) {
        auto current = queue.front();
        queue.pop();
        int current_x = current.first.first;
        int current_y = current.first.second;
        int depth = current.second;
        chessBoard[current_x][current_y] = depth;

        for (int i = 0; i < 8; i++) {
            int _x, _y;
            _x = current_x + dx[i];
            _y = current_y + dy[i];

            if (check(_x, _y)) {
                queue.push({{_x, _y}, depth + 1});
                visited[_x][_y] = true;
            }
        }
    }
}

void printChessBoard() {
    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= width; j++) {
            std::cout << std::left << std::setw(5) << chessBoard[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(chessBoard, -1, sizeof(chessBoard));

    std::cin >> length >> width >> horse_x >> horse_y;
    breadthFirstSearch(horse_x, horse_y);

    printChessBoard();

    return 0;
}
