#include <iostream>
#include <algorithm>

struct Apples{
    int height,cost;
};

bool cpr(Apples a, Apples b){
    return a.cost < b.cost;
}

int main(){
    int n,s,count = 0;
    std::cin >> n >> s;
    int chair,heightTao,sum;
    std::cin >> chair >> heightTao;
    sum = chair + heightTao;

    Apples ap[n];
    for (int i = 0; i < n; i++){
        std::cin >> ap[i].height >> ap[i].cost;
    }
    std::sort(ap,ap+n,cpr);

    for (int i = 0; i < n; i++){
        if (ap[i].height > sum) continue;;
        if (ap[i].cost > s) break;

        count++;
        s -= ap[i].cost;
    }

    std::cout << count << std::endl;

    return 0;
}