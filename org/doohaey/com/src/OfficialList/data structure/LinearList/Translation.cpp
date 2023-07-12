#include <iostream>
#include <queue>

int memory_capacity, space, consulting_count = 0;
bool inMemory[1010];
std::queue<int> memory;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> memory_capacity >> space;
    
    for (int i = 0; i < space; i++){
        int word;
        std::cin >> word;
        
        if (!inMemory[word]){
            consulting_count++;

            memory.push(word);
            inMemory[word] = true;
            if (memory.size() == 4) {
                inMemory[memory.front()] = false;
                memory.pop();
            }
        }
        
    }

    std::cout << consulting_count << std::endl;

    return 0;
}