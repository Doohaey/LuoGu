#include <iostream>
#include <algorithm>

int main(){
    int numCow,heightBookshelf,sum = 0;
    std::cin>>numCow>>heightBookshelf;
    
    int heightPerCow[numCow];
    for (int i = 0; i < numCow; i++) std::cin>>heightPerCow[i];
    std::sort(heightPerCow,heightPerCow+numCow);
    for (int j = numCow - 1; j >= 0; j--){
        sum += heightPerCow[j];
        if (sum >= heightBookshelf){
            std::cout<<numCow - j<<std::endl;
            break;
        }
    }

    return 0;
}