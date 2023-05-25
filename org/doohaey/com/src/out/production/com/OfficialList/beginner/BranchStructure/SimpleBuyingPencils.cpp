#include <bits/stdc++.h>
using namespace std;

// 声明 singleMinCost 函数
int singleMinCost(int nTotal, int n, int p);

int main(){
    int n, n1, n2, n3, p1, p2, p3;
    cin >> n >> n1 >> p1 >> n2 >> p2 >> n3 >> p3;

    int minCost = INT_MAX;

    for (int i = 0; i < 3; i++){
        int currentCost = 0;
        
        switch (i)
        {
        case 0:
            currentCost = singleMinCost(n, n1, p1);
            break;
        case 1:
            currentCost = singleMinCost(n, n2, p2);
            break;
        case 2:
            currentCost = singleMinCost(n, n3, p3);
            break;    
        default:
            break;
        }

        // 比较当前成本与最小成本
        if (currentCost < minCost) {
            minCost = currentCost;
        }
    }

    cout << minCost << endl;

    return 0;
}

int singleMinCost(int nTotal, int n, int p){
    int cost = 0, requiredPacks = 0;
    requiredPacks = (nTotal + n - 1) / n; // 向上取整
    cost = requiredPacks * p;
    return cost;
}
