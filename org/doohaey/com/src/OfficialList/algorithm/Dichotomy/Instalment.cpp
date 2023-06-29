#include <iostream>
#include <iomanip>
#include <cmath>

double principal,instalmentAmount;
int months;

int check(double mid){
    double sum = 0;
    for (int i = 1; i <= months; i++){
        sum += instalmentAmount / std::pow(1 + mid, i);  
    }

    if (sum == principal){
        return 0;
    } else {
        if (sum > principal){
            return 1;
        } else{
            return -1;
        }
    }
}

int main(){
    std::cin >> principal >> instalmentAmount >> months;

    double l = 0, r = 400, mid;
    while (r - l > 0.0001){
        mid = (l + r) / 2;

        if (!check(mid)){
            break;
        } else {
            if (check(mid) == 1){
                l = mid;
            } else {
                r = mid;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(1) << mid * 100 << std::endl;

    return 0;
}