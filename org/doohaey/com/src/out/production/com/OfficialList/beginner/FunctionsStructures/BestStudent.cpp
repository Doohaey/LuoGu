#include <iostream>
#include <string>
#include <vector>

struct person
{
    std::string name;
    int Chinese;
    int math;
    int English;
    int sum;

    person(){}

    person(std::string _name, int _Chinese, int _math, int _English, int _sum): name(_name), Chinese(_Chinese), math(_math), English(_English), sum(_sum){}
};

int main(){
    int n, MAX = -1;
    std::cin>>n;
    std::vector<person> gradeRecorder;
    person best;

    for (int i = 0; i < n; i++){
        std::string name;
        int Chinese,math,English,sum;
        std::cin>>name>>Chinese>>math>>English;
        sum = Chinese + math + English;
        person x = person(name,Chinese,math,English,sum);

        if (sum > MAX) {
            MAX = sum;
            best = x;
        }    
    }

    std::cout<<best.name<<" "<<best.Chinese<<" "<<best.math<<" "<<best.English;
}