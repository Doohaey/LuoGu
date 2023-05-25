#include <iostream>
#include <string>

char a[26];
int len;

void gen(char x, char y){
    len = y - x;
    if (len > 1){
        for (int i = 1; i < len ; i++) a[i] = (char)(x + i);
    }else if (len <= 0){
        a[1] = '-';
    }
}

void stringEx(int p1, int p2, int p3, std::string s){
    for (int i = 0; i < s.length(); i++){
        char c = s[i];

        if (c != '-') putchar(c);
        else {
            if (i > 0) {
                gen(s[i-1],s[i+1]);
                if (a[1] == '-') putchar(c);
                else {
                    if (p3 == 2) {
                        for (int k = 1; k <= len/2; k++){
                            char aux = a[k];
                            a[k] = a[len - k];
                            a[len - k] = aux;
                        }
                    }

                    for (int j = 1; j < len; j++){
                        if (p1 == 1){
                            a[j] = tolower(a[j]);
                        }else if (p1 == 2){
                            a[j] = toupper(a[j]);
                        }else if (p1 == 3)
                        {
                            a[j] = '*';
                        }

                        for (int l = 1; l <= p2; l++){
                            std::cout<<a[j];
                        }
                    }   
                }
            }else putchar(c);
        }
    }
    std::cout<<std::endl;
}

int main(){
    int p1,p2,p3;
    std::string s;
    std::cin>>p1>>p2>>p3;
    std::cin.ignore();
    std::getline(std::cin,s);

    stringEx(p1,p2,p3,s);
}