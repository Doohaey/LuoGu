#include <iostream>
#include <cmath>
#include <iomanip>

struct Point
{
    double x;
    double y;
};

double calDis(Point A, Point B){
    return std::pow(std::pow((A.x - B.x), 2) + std::pow((A.y - B.y), 2), 1.0 / 2);
}

int main(){
    double x, y, circle;
    Point triangle[3];
    for (int i = 0; i < 3; i++){
        std::cin >> x >> y;
        triangle[i] = {x, y};
    }

    circle = calDis(triangle[0], triangle[1]) + calDis(triangle[0], triangle[2]) + calDis(triangle[1], triangle[2]);
    std::cout << std::fixed << std::setprecision(2) << circle;

    return 0;
}
