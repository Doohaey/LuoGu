#include <iostream>
#include <vector>
#include <algorithm>

int upperBound,n,countGroup = 0;
int prices[30000];
bool selected[30000] = {false};

int main(){
    std::cin >> upperBound >> n;
    
    for (int i = 0; i < n; i++){
        std::cin >> prices[i];
    }

    std::sort(prices,prices+n);

    for (int j = 0; j < n; j++){
        if (selected[j]){
            continue;
        } else {
            for (int k = n - 1; k > j; k--){
                if (prices[j] + prices[k] <= upperBound && !selected[k]){
                    selected[k] = true;
                    break;
                }
            }
            countGroup++;
        }
    }

    std::cout << countGroup;
}
