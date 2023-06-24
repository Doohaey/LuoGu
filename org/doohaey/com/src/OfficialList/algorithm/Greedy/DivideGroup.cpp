#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int n,minLength = INT_MAX;
std::vector<int> power;
std::vector<std::vector<int>> groups; 

int main(){
    scanf("%d",&n);
    power.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d",&power[i]);
    }

    std::sort(power.begin(),power.end());

    while (n > 0){
        std::vector<int> group;
        group.push_back(power[0]);
        power.erase(power.begin());
        n--;
        for (int j = 0; j < n; j++){
            if (power[j] == group[group.size() - 1] + 1){
                group.push_back(power[j]);
                power.erase(power.begin()+j);
                j = j - 1;
                n--;
            }
        }
        groups.push_back(group);
    }

    for (std::vector<int> group : groups){
        if (group.size() < minLength){
            minLength = group.size();
        }
    }

    printf("%d",minLength);

    return 0;
}