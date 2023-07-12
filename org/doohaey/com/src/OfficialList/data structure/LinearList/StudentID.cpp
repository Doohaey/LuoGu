#include <iostream>

int main(){
    int n, m, enquire;
    std::cin >> n >> m;
    int IDs[n];
    for (int i = 0; i < n; i++){
        std::cin >> IDs[i];
    }
    for (int j = 0; j < m; j++){
        std::cin >> enquire;
        std::cout << IDs[enquire-1] << std::endl;
    }

    return 0;
}