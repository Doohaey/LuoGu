#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,s,t;
	cin>>m>>t>>s;
	if(t==0) {
		cout<<0<<endl;
	}
	int a=s/t;
	if(s%t!=0) a++;
	if(m-a<0) cout<<0<<endl;
	else cout<<m-a<<endl;
}