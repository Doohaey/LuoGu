#include <iostream>
#include <iomanip>

double a,b,c,d;
int rootFound = 0;

double function(double x){
    return a*x*x*x + b*x*x + c*x + d;
}

void countRoot(double i){
    rootFound++;
    std::cout << std::fixed << std::setprecision(2) << i ;
    if (rootFound != 3){
        std::cout << " ";
    } else {
        std::cout << std::endl;
    }
}

int main(){
    std::cin >> a >> b >> c >> d;

    for (int i = -100; i < 100; i++){
        if (function(i) == 0){
            countRoot(i);
        } else if (function(i) * function (i+1) < 0){
            double l = i, r = i + 1,mid;
            while (r - l > 0.001){
                mid = (l + r) / 2;

                if (function(mid) == 0){
                    countRoot(mid);
                } else if (function(i)*function(mid) > 0){
                    l = mid;
                } else {
                    r = mid;
                }
            }

            countRoot(mid);
        }

        if (rootFound == 3){
            break;
        }

    }

    return 0;
}