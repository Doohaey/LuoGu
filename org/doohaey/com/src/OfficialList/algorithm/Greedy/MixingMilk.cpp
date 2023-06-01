#include <iostream>
#include <algorithm>

typedef long long llg;

struct Farmer{
    int price,amount;
};

bool cmp(Farmer a, Farmer b){
    return a.price < b.price;
}

int main(){
    int n,m;
    llg collected = 0,cost = 0;
    std::cin >> n >> m;
    Farmer fr[m];
    for (int i = 0; i < m; i++){
        std::cin >> fr[i].price >> fr[i].amount;
    }

    std::sort(fr,fr+m,cmp);

    for (int i = 0; i < m; i++){
        if (collected + fr[i].amount <= n){
            collected += fr[i].amount;
            cost += fr[i].amount * fr[i].price;
        } else {
            cost += (n - collected) * fr[i].price;
            break;
        }
    }

    std::cout << cost;
}