#include <iostream>
#include <string>

int transform(std::string str){
    int transTo = 1;
    for (char a : str) transTo *= (int) (a - 'A' + 1);
    transTo = transTo % 47;
    return transTo;
}

int main(){
    std::string comet,group;
    std::cin>>comet>>group;
    int modComet,modGroup;
    modComet = transform(comet);
    modGroup = transform(group);

    if (modComet == modGroup) std::cout<<"GO";
    else std::cout<<"STAY";

    return 0 ;
}