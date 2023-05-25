#include <cstdio>
#include <vector>
int n,lineCount = 0;
std::vector<std::vector<int>> statistics;

void genSchem(int x, int sum, std::vector<int> line){
    for (int i = 1; i <= 3; i++){
        if (sum + i > n || (x > 0 && sum + i == n)) break;
        else {
            sum += i;
            line.push_back(i);
            if (x > 0){
                genSchem(x-1,sum,line);
            }else{
                if (sum == n){
                    statistics.push_back(line);
                    lineCount++;
                    break;
                }    
            }
            line.pop_back();
            sum -= i;
        }
    }
}

void printSchem(){
    printf("%d\n",lineCount);
    for (std::vector<int> vi : statistics){
        for (int j = 0; j < 10; j++){
            printf("%d",vi[j]);
            (j != 9) ? printf(" ") : printf("\n");
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
        printSchem();
    }

    return 0;
}