#include <iostream>
#include <string>

struct person
{
    std::string id;
    int age;
    int grade;
};

int main(){
    int n;
    std::cin>>n;
    person oiers;

    for (size_t i = 0; i < n; i++){
        std::cin>>oiers.id>>oiers.age>>oiers.grade;
        oiers.age += 1;
        oiers.grade *= 6;
        oiers.grade /= 5;
        if (oiers.grade > 600) oiers.grade = 600;
        std::cout<<oiers.id<<" "<<oiers.age<<" "<<oiers.grade<<std::endl; 
    }
}