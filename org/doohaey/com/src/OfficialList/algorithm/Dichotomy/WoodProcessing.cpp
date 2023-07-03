#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long llg;

int n,k;
llg sum = 0;
int partial_length;

bool check(int _length, int n,int wood_length[]){
    if (_length == 0){
        return true;
    }
    
    int _k = 0;
    for (int i = 0; i < n; i++){
        _k += wood_length[i] / _length;
    }
    
    return _k >= k;
}

int main(){
    scanf("%d %d",&n,&k);
    int wood_length[n];
    memset(wood_length,0,sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d",&wood_length[i]);
        sum += wood_length[i];
    }
    std::sort(wood_length,wood_length+n);

    int l = 0, r = sum / k, mid;
    while (l <= r){
        mid = l + (r - l) / 2;
        if (check(mid,n,wood_length)){
            partial_length = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    } 
    
    printf("%d\n",partial_length);

    return 0;
}