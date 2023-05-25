#include <iostream>

int main(){
    int n,aux;
    std::cin>>n;
    for (int nom = n; nom >= 0; nom--) {
        std::cin>>aux;
        if (aux){
            if (aux > 0 && nom != n) std::cout<<"+";

            if (aux == -1) {
                std::cout<<"-";
                if (nom == 0) std::cout<<"1";
            }
            else if (aux == 1 && nom == 0)  std::cout<<"1";
            else if (aux != 1 && aux != -1) std::cout<<aux;

            if (nom > 1) std::cout<<"x^"<<nom;
            else if (nom == 1) std::cout<<"x";            
        }
    }
    return 0;
}