#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int s[4];
std::vector<std::vector<int>> tab;

void genStack(int s){

}

int minTime(int i, int left, int stack[2]){
    if (left > 0){
        
    }
}

int main() {
    std::cin>>s[0]>>s[1]>>s[2]>>s[3];
    for (int i = 0; i < 4; i++){
        std::vector<int> line;
        for (int j = 0; j < s[i]; j++){
            int dig;
            std::cin>>dig;
            line.push_back(dig); 
        }
        tab.push_back(line);
    }
    
    for (int i = 0; i < 4; i++){
        int stack[2] = {0};
        int time = minTime(i,tab[i].size(),stack);
    }

    return 0;
}




