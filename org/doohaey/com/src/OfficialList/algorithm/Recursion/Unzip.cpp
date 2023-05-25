#include <iostream>
#include <string>

std::string unzip(std::string s,int times){
    std::string part,ans,temp;
    int unpairedBrackets = 0, recursionTimes = 0;
    bool readingDigit = false;

    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        if (!(c >= '0' && c <= '9')){
            readingDigit = false;
        }

        if (readingDigit){
            recursionTimes = recursionTimes * 10 + (int)(c - '0');
        }else if (c == '[') {
            unpairedBrackets++;
            if (unpairedBrackets > 1) temp.push_back(c);
            else readingDigit = true;
        }else if (c == ']') {
            unpairedBrackets--;
            if (unpairedBrackets) temp.push_back(c);
            else {
                temp = unzip(temp, recursionTimes);
                part += temp;
                temp.clear();
                recursionTimes = 0;
            }
        }else if (unpairedBrackets) {
            temp.push_back(c);
        }    
        else {
            part.push_back(c);
        }
    }

    for (int i = 0; i < times; i++){
        ans += part;
    }

    return ans;
}

int main(){
    std::string s,ans;
    std::getline(std::cin,s);
    ans = unzip(s,1);
    std::cout<<ans;
}