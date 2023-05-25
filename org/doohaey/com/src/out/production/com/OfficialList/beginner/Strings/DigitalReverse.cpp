#include <iostream>
#include <string>
#include <vector>

void reverse(std::string &str){
    bool isLeadingZero = true;
    std::string auxStr;
    for (int i = str.size() - 1; i >= 0; i--){
        char c = str.at(i);
        if (c != '0') isLeadingZero = false;
        if (!isLeadingZero) auxStr.push_back(c);
    }
    str = auxStr;
}

void removeEndZero(std::string &str){
    reverse(str);
    reverse(str);
}

int main(){
    std::string s;
    std::cin>>s;

    std::string upperPart;
    std::string lowerPart;
    char delimiter = '\0';
    bool afterDelimiter = false;
    bool isDemical = false;
    for (char c : s){
        if (c == '.' || c == '/'|| c == '%'){
            delimiter = c;
            if (c == '.' || c == '/') afterDelimiter = true;
            if (c == '.') isDemical = true;
        }
        else if (!afterDelimiter) upperPart.push_back(c);
        else if  (afterDelimiter) lowerPart.push_back(c);  
    }

    bool isAllZero = true;
    for (char c : upperPart) if (c != '0') isAllZero = false;
    if (isAllZero) upperPart = '0'; 
    else reverse(upperPart);

    std::cout<<upperPart;

    if (delimiter == '%') std::cout<<delimiter;

    if (afterDelimiter) {
        std::cout<<delimiter;

        isAllZero = true;
        for (char c : lowerPart) if (c != '0') isAllZero = false;
        if (isAllZero) lowerPart = '0'; 
        else{
            reverse(lowerPart);
            if (isDemical) removeEndZero(lowerPart);
        }    
        std::cout<<lowerPart;
    }
}


