#include <iostream>
#include <vector>
int n;

void genSchem(int x, int sum, std::vector<int> line){
    for (int i = 1; i <= 3; i++){
        if (sum + i > n) break;
        else {
            sum += i;
            line.push_back(i);
            if (x > 0){
                genSchem(x-1,sum,line);
            }else{
                if (sum == n){
                    for (int j = 0; j < 10; j++){
                        printf("%d",line[j]);
                        (j != 9) ? printf(" "):printf("\n");
                    }
                    break;
                }    
            }
            line.pop_back();
            sum -= i;
        }
    }
}

int main(){
    scanf("%d",&n);
    if (n < 10 || n > 30) {
        printf("0");
    }
    else {
        std::vector<int> line;
        genSchem(9,0,line);
    }

    return 0;
}