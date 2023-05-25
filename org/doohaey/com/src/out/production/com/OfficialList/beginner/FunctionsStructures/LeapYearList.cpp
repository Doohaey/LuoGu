#include <iostream>
#include <vector>

bool isLeapYear(int year){
    bool isLeapYear = false;
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) isLeapYear = true;
    return isLeapYear;
}

int main(){
    int begin,end;
    std::cin>>begin>>end;
    std::vector<int> leapYears;

    for (int i = begin; i <= end; i++){
        bool leapYear = isLeapYear(i);
        if (leapYear) leapYears.push_back(i);
    }

    std::cout<<leapYears.size()<<std::endl;
    
    for (int j = 0; j < leapYears.size(); j++){
        std::cout<<leapYears.at(j);
        if (j != leapYears.size() - 1) std::cout<<" ";
    }
}