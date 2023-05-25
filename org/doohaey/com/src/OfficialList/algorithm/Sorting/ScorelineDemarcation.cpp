#include <iostream>
#include <string>
#include <algorithm>

struct Candidate{
    int id;
    int grades;
};

bool compare(const Candidate &a, const Candidate &b) {
    if (a.grades == b.grades) {
        return a.id < b.id;
    }
    return a.grades > b.grades;
}


int main(){
    int total,admissionPlan,totalInterview,interviewScore;
    std::cin>>total>>admissionPlan;
    totalInterview = (admissionPlan * 3) / 2; 
    Candidate st[total];
    
    for (int i = 0; i < total; i++){
        std::cin>>st[i].id>>st[i].grades;
    }
    std::sort(st,st + total, compare);
    interviewScore = st[totalInterview - 1].grades;

    totalInterview = 0;
    for (int j = 0; st[j].grades >= interviewScore; j++){
        totalInterview++;
    }

    std::cout<<interviewScore<<" "<<totalInterview<<std::endl;
    for (int j = 0; st[j].grades >= interviewScore; j++){
        std::cout<<st[j].id<<" "<<st[j].grades<<std::endl;
    }

    return 0;
}