#include <iostream>

struct Point{
    int x, y;
};

int length, width, obstacles_count;
int directionX[4] = {0, 1, 0, -1}, directionY[4] = {1, 0, -1, 0};
Point origin, terminal, obstacle;
bool maze[5][5];
int routes_count = 0;

bool isValid(Point p){
    return p.x >= 0 && p.y >= 0 && p.x < length && p.y < width && !maze[p.x][p.y];
}

void deepFirstSearch(Point p){
    if (p.x == terminal.x && p.y == terminal.y){
        routes_count++;
        return;
    }

    for (int i = 0; i < 4; i++){
        Point p_next;
        p_next.x = p.x + directionX[i];
        p_next.y = p.y + directionY[i];
        if (isValid(p_next)){
            maze[p_next.x][p_next.y] = true;
            deepFirstSearch(p_next);
            maze[p_next.x][p_next.y] = false;
        }
    }

    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> length >> width >> obstacles_count;
    std::cin >> origin.x >> origin.y >> terminal.x >> terminal.y;

    origin.x--; origin.y--;
    terminal.x--; terminal.y--;

    maze[origin.x][origin.y] = true;

    while(obstacles_count--){
        std::cin >> obstacle.x >> obstacle.y;
        obstacle.x--; obstacle.y--;
        maze[obstacle.x][obstacle.y] = true;
    }

    deepFirstSearch(origin);

    std::cout << routes_count << std::endl;

    return 0;
}
