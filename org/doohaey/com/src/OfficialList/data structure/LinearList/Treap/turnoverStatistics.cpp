#include <iostream>
#include <set>

int n, x;
long long sum = 0;
std::set<int> treap;

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> x;
        treap.insert(x);

        if (i == 1) sum += x;
        else 
        {

        }    
    }

    return 0;
}





