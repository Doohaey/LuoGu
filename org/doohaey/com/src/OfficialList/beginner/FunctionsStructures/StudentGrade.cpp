#include <iostream>

struct StudentGrade
{
    int name;
    int academic;
    int extracurricular;

    StudentGrade(){}

    StudentGrade(int _name, int _academic, int _extracurricular) : name(_name), academic(_academic), extracurricular(_extracurricular){}
};

int main(){
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++){
        StudentGrade sg;
        std::cin>>sg.name>>sg.academic>>sg.extracurricular;

        if (sg.academic * 7 + sg.extracurricular * 3 >= 800 && sg.academic + sg.extracurricular > 140) {
            std::cout << "Excellent";
        } else {
            std::cout << "Not excellent";
        }
        std::cout << std::endl; 
    }
}
