#include <iostream>
#include <queue>

int n, square[32][32], check[32][32] = {0};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct point {
    int x;
    int y;
};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x <= n+1 && y <= n+1 && !check[x][y] && square[x][y] != 1;
}

void breadth_first_search(int x, int y){
    std::queue<point> q;
    q.push({x,y});
    check[x][y] = 1;

    while(!q.empty()){
        point current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (isValid(nx,ny)){
                q.push({nx,ny});
                check[nx][ny] = 1;
            }
        }
    }
}

void output(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(check[i][j] == 1 || square[i][j] == 1) {
                std::cout << square[i][j] << " ";
            } else {
                std::cout << "2 ";
            }
        }
        std::cout << std::endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            std::cin >> square[i][j];
        }
    }

    breadth_first_search(0,0);

    output();

    return 0;
}
