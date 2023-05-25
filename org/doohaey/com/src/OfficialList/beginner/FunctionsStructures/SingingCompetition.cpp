#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>

std::vector<double> averageScore;

 void readTable(int n, int m) {
    for (int i = 0; i < n; i++) {
        int sumScore = 0,MIN = INT_MAX, MAX = 0;
        for (int j = 0; j < m; j++) {
            int singleScore;
            std::cin >> singleScore;
            sumScore += singleScore;
            if (singleScore < MIN) MIN = singleScore;
            if (singleScore > MAX) MAX = singleScore;
        }
        double _averageScore = (sumScore - MIN - MAX) / static_cast<double>(m - 2);
        averageScore.push_back(_averageScore);
    }
}


void findAndCout(std::vector<double> averageScore){
    double max = 0;
    for (double _averageScore : averageScore){
        if (_averageScore > max) max = _averageScore;
    }
    std::cout<<std::fixed<<std::setprecision(2)<<max;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    readTable(n, m);
    findAndCout(averageScore);
    return 0;
}

