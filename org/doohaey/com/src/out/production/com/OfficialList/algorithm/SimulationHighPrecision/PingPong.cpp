#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define COUNT_ROUND1 11
#define COUNT_ROUND2 21

void printResult(std::vector<char> sum, int roundPoints){
    int countWin = 0, countLose = 0;
    for (char c : sum){
        if (c == 'W') countWin++;
        if (c == 'L') countLose++;

        if ((countWin >= roundPoints || countLose >= roundPoints) && abs(countWin - countLose) >= 2){
            std::cout << countWin << ':' << countLose << std::endl;
            countWin = 0;
            countLose = 0;
        }
    }

    std::cout << countWin << ":" << countLose << std::endl;
}

int main(){
    std::vector<char> sum;
    bool isEnd = false;

    while (!isEnd)
    {
        char c = getchar();
        if (c == 'E') isEnd = true;
        else sum.push_back(c);
    }

    printResult(sum, COUNT_ROUND1);
    std::cout << std::endl;
    printResult(sum, COUNT_ROUND2);

    return 0;
}
