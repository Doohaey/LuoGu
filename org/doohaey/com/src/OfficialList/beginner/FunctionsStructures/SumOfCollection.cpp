#include <iostream>
#include <vector>
#include <cstdint>

void input(std::vector<int>& collection){
    int element;
    while (std::cin >> element)
    {
        collection.push_back(element);
    }
}

int64_t sumOfSubsets(std::vector<int> &collection){
    int64_t sum = 0;
    int n = collection.size();
    int64_t appearance_count = (1LL << (n - 1));

    for (int element : collection){
        sum += element * appearance_count;
    }

    return sum;
}

int main(){
    std::vector<int> collection;
    input(collection);
    int64_t sum = sumOfSubsets(collection);
    std::cout << sum << std::endl;

    return 0;
}
