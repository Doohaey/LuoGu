#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int m,n;
long long unsatisfactionValue = 0;
std::vector<int> lines,grades;

int main(){
    std::cin >> m >> n;
    lines.resize(m);
    grades.resize(n);
    for (int i = 0; i < m; i++){
        std::cin >> lines[i];
    }
    for (int i = 0; i < n; i++){
        std::cin >> grades[i];
    }

    std::sort(lines.begin(),lines.end());

    for (int i = 0; i < n; i++){
        auto properCollege = std::lower_bound(lines.begin(),lines.end(),grades[i]);
        if (properCollege != lines.end() && properCollege != lines.begin()){
            int properIdx = properCollege - lines.begin() - 1;
            unsatisfactionValue += std::min(grades[i] - lines[properIdx],lines[properIdx+1] - grades[i]);
        } else {
            if (properCollege == lines.end()){
                unsatisfactionValue += grades[i] - lines[n-1];
            } else {
                unsatisfactionValue += lines[0] - grades[i];
            }
        }
    }

    std::cout << unsatisfactionValue << std::endl;
}