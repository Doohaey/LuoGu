#include <iostream>
#include <cstring>
typedef long long llg;

llg memoizationSearch[21][21][21];

llg functionW(llg a, llg b, llg c){
    if (a <= 0 || b <= 0 || c <= 0){
        return 1;
    }else if (a < b && b < c) {
        memoizationSearch[a][b][c] = functionW(a,b,c-1) + functionW(a,b-1,c-1) - functionW(a,b-1,c);
    }    
    else {
        memoizationSearch[a][b][c] = functionW(a-1,b,c) + functionW(a-1,b-1,c) + functionW(a-1,b,c-1) - functionW(a-1,b-1,c-1);
    }
    return memoizationSearch[a][b][c];
}

int main(){
    llg a,b,c;
    while (std::cin>>a>>b>>c){
        std::memset(memoizationSearch,0,sizeof(memoizationSearch));
        
        if (a == -1 && b == -1 && c == -1) break;
        std::cout<<"w("<<a<<","<<b<<","<<c<<") = ";
        if (a > 20 || b > 20 || c > 20){
            a = 20;
            b = 20;
            c = 20;
        }

        std::cout<<functionW(a,b,c)<<std::endl;
    }
}