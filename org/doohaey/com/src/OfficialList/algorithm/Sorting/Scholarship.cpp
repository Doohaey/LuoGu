#include <iostream>
#include <algorithm>

struct Student {
    int id;
    int chinese;
    int math;
    int english;
    int total;
};

bool cmp(Student a, Student b) {
    if (a.total != b.total) return a.total > b.total;
    else if (a.chinese != b.chinese) return a.chinese > b.chinese;
    else return a.id < b.id;
}

int main() {
    int n;
    std::cin >> n;
    Student students[n];

    for (int i = 0; i < n; i++) {
        students[i].id = i + 1;
        std::cin >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }

    std::sort(students, students + n, cmp);

    for (int i = 0; i < 5; i++) std::cout << students[i].id << " " << students[i].total << std::endl;

    return 0;
}
