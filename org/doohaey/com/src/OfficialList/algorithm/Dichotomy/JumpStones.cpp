#include <iostream>
#include <vector>

int distance, stones, remove_upperbound;
int min_jump;
std::vector<int> pos_stones;

bool check(int _min_jump){
    int remove_temp = 0, pos_temp = 0;
    for (int i = 1; i <= stones + 1; i++){
        int single_distance = pos_stones[i] - pos_stones[pos_temp];
        if (single_distance < _min_jump){
            remove_temp++;
        } else {
            pos_temp = i;
        }
    }


    return remove_temp <= remove_upperbound;
}

void dichotomy(){
    int l = 1, r = distance, mid;
    while (l <= r){
        mid = l + (r - l) / 2;
        if (check(mid)){
            min_jump = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}

int main(){
    std::cin >> distance >> stones >> remove_upperbound;
    pos_stones.resize(stones + 2);
    for (int i = 1; i <= stones; i++){
        std::cin >> pos_stones[i];
    }
    pos_stones[0] = 0;              
    pos_stones[stones + 1] = distance;

    dichotomy();

    std::cout << min_jump << std::endl;

    return 0;
}
