#include <cstdio>
#include <vector>

int mileage,signpost_inhere,signpost_to_set;
int idx;
std::vector<int> pos;

inline bool check(int _idx){
    int signpost_newly_set = 0;
    int countStart = 0;
    for (int i = 1; i <= signpost_inhere + 1; i++){
        if (pos[i] - countStart > _idx){
            signpost_newly_set++;
            countStart += _idx;
            i--; 
        } else {
            countStart = pos[i];
        }

        if (signpost_newly_set > signpost_to_set){
            return false;
        }
    }

    return true;
}

void dichotomy(){
    int l = 0, r = mileage, mid;
    while (l <= r){
        mid = l + (r - l) / 2;
        if (check(mid)){
            idx = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}

int main(){
    scanf("%d %d %d",&mileage,&signpost_inhere,&signpost_to_set);
    pos.resize(signpost_inhere+2);
    pos[0] = 0;
    pos[signpost_inhere+1] = mileage;
    for (int i = 1; i <= signpost_inhere; i++){
        scanf("%d",&pos[i]);
    }

    dichotomy();

    printf("%d",idx);

    return 0;
}