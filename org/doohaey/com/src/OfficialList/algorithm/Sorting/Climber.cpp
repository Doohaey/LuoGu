#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct coordinates{
    int x,y,z;
};

bool compareAltitude(coordinates a, coordinates b){
    return a.z < b.z;
}

int main(){
    int n;
    std::cin>>n;
    coordinates points[n];
    for (int i = 0; i < n; i++) std::cin>>points[i].x>>points[i].y>>points[i].z;
    std::sort(points,points+n,compareAltitude);
    double distance = 0;
    for (int j = 0; j < n - 1; j++){
        distance += std::sqrt(std::pow((points[j].x - points[j+1].x),2)+std::pow((points[j].y - points[j+1].y),2)+std::pow((points[j].z - points[j+1].z),2));
    }
    std::cout<<std::fixed<<std::setprecision(3)<<distance<<std::endl;
}