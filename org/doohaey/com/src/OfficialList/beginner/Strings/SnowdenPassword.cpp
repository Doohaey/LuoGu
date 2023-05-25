#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

int convertNumber(std::string& word) {
    if (word == "one" || word == "a" || word == "another" || word == "first") return 1;
    if (word == "two" || word == "both" || word == "second") return 2;
    if (word == "three" || word == "third") return 3;
    if (word == "four") return 4;
    if (word == "five") return 5;
    if (word == "six") return 6;
    if (word == "seven") return 7;
    if (word == "eight") return 8;
    if (word == "nine") return 9;
    if (word == "ten") return 10;
    if (word == "eleven") return 11;
    if (word == "twelve") return 12;
    if (word == "thirteen") return 13;
    if (word == "fourteen") return 14;
    if (word == "fifteen") return 15;
    if (word == "sixteen") return 16;
    if (word == "seventeen") return 17;
    if (word == "eighteen") return 18;
    if (word == "nineteen") return 19;
    if (word == "twenty") return 20;
    return 0;
}

int main(){
    std::string word;
    std::vector<int> packet;
    int num = 0;
    while(std::cin>>word){
        if (word.at(0) == '.') break;
        int strInt = ((int)std::pow(convertNumber(word),2) % 100);
        if (strInt != 0) packet.push_back(strInt);
    }

    std::sort(packet.begin(),packet.end());
    for (int i = 0; i < packet.size(); i++){
        num *= 100;
        num += packet.at(i);
    }
    std::cout<<num;
}