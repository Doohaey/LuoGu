#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin>>s;
    for (int i = 0; i < s.size(); i++){
        if (s.at(i) >= 'a' && s.at(i) <= 'z'){
            s.at(i) = (char)(s.at(i) + 'A' - 'a'); 
        }
        std::cout<<s.at(i);
    }

    return 0;
}