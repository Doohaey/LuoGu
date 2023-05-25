#include <cstdio>
#include <climits>

int n,m,ans = INT_MAX;
char flag[50][50];

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf(" %c",&flag[i][j]);
        }
    }
   
    for (int wlbound = 0; wlbound < n - 2; wlbound++){
        for (int blbound = wlbound + 1; blbound < n - 1; blbound++){
            int sum = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (i <= wlbound && flag[i][j] != 'W') sum++;
                    if (i <= blbound && i > wlbound && flag[i][j] != 'B') sum++;
                    else if (i > blbound && flag[i][j] != 'R') sum++;
                }
            }
            if (sum < ans) ans = sum;
        }
    }

    printf("%d",ans);

    return 0;
}

