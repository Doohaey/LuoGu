#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int n,minLength = INT_MAX;
std::vector<int> powerValue;
std::vector<std::vector<int>> groups;

void newTeam(int i){
    std::vector<int> group;
    group.push_back(powerValue[i]);
    groups.insert(groups.begin(),group);
}

void putIn(int i){
    bool inserted = false;
    for (int j = 0; j < groups.size(); j++){
        if (groups[j][groups[j].size() - 1] == powerValue[i] - 1){
            groups[j].push_back(powerValue[i]);
            inserted = true;
            if (j < groups.size() - 1 && groups[j+1].size() < groups[j].size()){
                std::vector<int> aux = groups[j+1];
                groups[j+1] = groups[j];
                groups[j] = aux;
            }
            break;
        }
    }

    if (!inserted){
        newTeam(i);
    }
}

int main(){
    std::cin >> n;
    powerValue.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d",&powerValue[i]);
    }

    std::sort(powerValue.begin(),powerValue.end());

    for (int i = 0; i < n; i++){
        if (i == 0){
            newTeam(i);
        } else {
            putIn(i);
        }
    }

    for (std::vector<int> group : groups){
        if (group.size() < minLength){
            minLength = group.size();
        }
    }

    std::cout << minLength << std::endl;
}    