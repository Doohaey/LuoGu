#include <iostream>

typedef long long llg;

int main(){
    int n,x;
    llg count = 0;
    std::cin >> n >> x;
    int boxes[n];
    for (int i = 0; i < n; i++){
        std::cin >> boxes[i];
    }

    for (int i = 0; i < n - 1; i++){
        while (boxes[i] + boxes[i+1] > x){
            if (boxes[i+1] > 0){
                if (x > boxes[i]){
                    int minus = boxes[i] + boxes[i+1] - x;
                    boxes[i+1] -= minus;
                    count += minus;
                }else{
                    count += boxes[i+1];
                    boxes[i+1] = 0;
                } 
            }else{
                count += boxes[i] - x;
                boxes[i] = x;
            }
        }
    }

    std::cout << count;
}