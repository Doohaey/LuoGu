#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> perTime(n);
    std::multimap<int,int> queue;
    for (int i = 0; i < n; i++) {
        std::cin >> perTime[i];
        queue.insert(std::make_pair(perTime[i],i + 1));
    }

    std::sort(perTime.begin(),perTime.end());

    double time = 0;
    double totalWaitTime = 0;
    for (int i = 0; i < n; i++){
        if (i > 0) {
            time += perTime[i-1];
            totalWaitTime += time;
        }

        auto range = queue.equal_range(perTime[i]);
        if (range.first != queue.end()) {
            std::cout << range.first->second;
            queue.erase(range.first);
        }

        if (i != n - 1){
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }

    }

    double averageWaitTime = totalWaitTime / n;
    std::cout << std::fixed << std::setprecision(2) << averageWaitTime << std::endl;
}
