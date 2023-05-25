#include <iostream>
#include <cstring>
#include <algorithm>

struct Candidate{
    int id;
    std::string ballots;
};

bool cmp(Candidate a, Candidate b){
    if (a.ballots.length() != b.ballots.length()) return a.ballots.length() > b.ballots.length();
    else {
        return a.ballots > b.ballots;
    }
}

int main(){
    int n;
    std::cin>>n;
    Candidate cds[n];
    for (int i = 0; i < n; i++){
        std::cin>>cds[i].ballots;
        cds[i].id = i + 1;
    }
    std::sort(cds,cds+n,cmp);
    std::cout<<cds[0].id<<std::endl<<cds[0].ballots<<std::endl;

    return 0;
}