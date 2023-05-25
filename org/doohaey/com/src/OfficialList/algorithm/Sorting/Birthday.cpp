#include <iostream>
#include <algorithm>
#include <cstring>

struct Birthday
{
    std::string name;
    int year;
    int month;
    int day;
    int serialInput;
};

bool timeCompare(Birthday a, Birthday b){
    if (a.year != b.year) return a.year < b.year;
    else if (a.month != b.month) return a.month < b.month;
    else if (a.day != b.day) return a.day < b.day;
    else return a.serialInput > b.serialInput;
}

int main(){
    int n;
    std::cin>>n;
    Birthday students[n];
    for (int i = 0; i < n; i++){
        std::cin>>students[i].name>>students[i].year>>students[i].month>>students[i].day;
        students[i].serialInput = i;
    }
    std::sort(students,students+n,timeCompare);
    for (int j = 0; j < n; j++){
        std::cout<<students[j].name<<std::endl;
    }
}