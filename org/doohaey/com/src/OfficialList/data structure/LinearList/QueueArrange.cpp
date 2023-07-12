#include <iostream>

struct Node{
    int l = -1, r = -1;
    bool visible = false; 
}queue[100010];

int m, n, start_index;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> m;
    queue[1].visible = true;
    for (int i = 2; i <= m; i++){
        queue[i].visible = true;
        int k, q;
        std::cin >> k >> q;
        if (q == 0){
            if (queue[k].l == -1){
                start_index = i;
                queue[i].l = -1;
            } else {
                queue[queue[k].l].r = i;
                queue[i].l = queue[k].l;
            }
            queue[k].l = i;
            queue[i].r = k;
        } else {
            if (queue[k].r != -1){
                queue[queue[k].r].l = i;
                queue[i].r = queue[k].r;
            } else {
                queue[i].r = -1;
            }
            queue[k].r = i;
            queue[i].l = k;
        }
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        std::cin >> x;
        queue[x].visible = false;
    }

    int p = start_index;
    for (int i = 1; i <= m; i++){
        if (queue[p].visible){
            std::cout << p << " ";
        }
        p = queue[p].r;
    }    

    return 0;
}