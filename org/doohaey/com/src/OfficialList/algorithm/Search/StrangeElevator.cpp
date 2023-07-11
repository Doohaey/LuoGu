#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

int floors, departure, terminal;
std::vector<int> index_floors, distance;

void breadth_first_search() {
    distance.resize(floors + 1, -1);
    std::queue<int> q;
    distance[departure] = 0;
    q.push(departure);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        int next;
        next = current - index_floors[current];
        if (next >= 1 && distance[next] == -1) {
            distance[next] = distance[current] + 1;
            q.push(next);
        }
        next = current + index_floors[current];
        if (next <= floors && distance[next] == -1) {
            distance[next] = distance[current] + 1;
            q.push(next);
        }
    }
    std::cout << distance[terminal] << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> floors >> departure >> terminal;
    index_floors.resize(floors + 1);
    for (int i = 1; i <= floors; i++) {
        std::cin >> index_floors[i];
    }

    breadth_first_search();

    return 0;
}
