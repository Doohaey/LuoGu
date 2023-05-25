#include<bits/stdc++.h>
using namespace std;

int main(){
    int w,x,h,q,count = 0;
    cin>>w>>x>>h>>q;
    
    bool cube[w+1][x+1][h+1] = {false};
    
    while(q--){
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                for(int k = z1; k <= z2; k++)
                {
                    cube[i][j][k]=true;
                }
            }
        }
    }      

    for (int i = 1; i < w + 1; i++){
            for (int j = 1; j < x + 1; j++){
                for (int k = 1; k < h + 1; k++){
                    if (!cube[i][j][k]) count++; 
            }
        }
    }

    cout<<count; 
}