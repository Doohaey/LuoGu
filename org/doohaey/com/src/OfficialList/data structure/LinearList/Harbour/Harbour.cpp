#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct Ship
{
    int t, k, inner_nationalities[300010] = {0};
    std::vector<int> inner_nationalities_list;
};

int n, nationalities[300010] = {0};
std::map<int, int> nationalities_list;
std::vector<Ship> ships;
std::queue<Ship> daily_ships;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    ships.resize(n + 1);

    for (int i = 1; i <= n; i++){
        std::cin >> ships[i].t >> ships[i].k;
        for (int j = 1; j <= ships[i].k; j++){
            int x;
            std::cin >> x;

            if (!ships[i].inner_nationalities[x]) {
                ships[i].inner_nationalities_list.push_back(x);
            }
            ships[i].inner_nationalities[x]++;
        }

        for (int k = 0; k < ships[i].inner_nationalities_list.size(); k++){
            if (!nationalities[ships[i].inner_nationalities_list[k]]){
                nationalities_list[ships[i].inner_nationalities_list[k]] = ships[i].inner_nationalities_list[k];
            }
            nationalities[ships[i].inner_nationalities_list[k]] += ships[i].inner_nationalities[ships[i].inner_nationalities_list[k]];
        }

        daily_ships.push(ships[i]);
        while (!daily_ships.empty() && ships[i].t - daily_ships.front().t >= 86400){
            Ship temp = daily_ships.front();
            daily_ships.pop();

            for (int k = 0; k < temp.inner_nationalities_list.size(); k++){
                nationalities[temp.inner_nationalities_list[k]] -= temp.inner_nationalities[temp.inner_nationalities_list[k]];
                if (nationalities[temp.inner_nationalities_list[k]]){
                    nationalities_list.erase(temp.inner_nationalities_list[k]);
                }
            }
        }

        std::cout << nationalities_list.size() << std::endl;
    }

    return 0;
}
