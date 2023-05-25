#include <iostream>


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n;
    std::cin>>n;
    int tag[n];
    for (int i = 0; i < n; i++) std::cin>>tag[i];
    
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (tag[i] > tag[j]) {
                swap(tag[i],tag[j]);
                count++;
            }
        }
    }
    std::cout<<count;

    return 0;
}