#include <bits/stdc++.h>
using namespace std;
int n,m,r,k;
char d[10008];
int a[10008],b[10008],c[10008],step;
bool ch()
{
  for(int i=1;i<=r/2;i++)
  if(a[i]!=a[r-i+1])
  return 0;
  return 1;
}
int main()
{
    cin>>n>>d;
    
  for(int i=0;i<strlen(d);i++)
  {
    if(d[i]=='A')
    a[i+1]=10;
    else if(d[i]=='B')
    a[i+1]=11;
    else if(d[i]=='C')
    a[i+1]=12;
    else if(d[i]=='D')
    a[i+1]=13;
    else if(d[i]=='E')
    a[i+1]=14;
    else if(d[i]=='F')
    a[i+1]=15;
    else a[i+1]=d[i]-'0';
  }
  r=strlen(d);
    while(!ch()&&step<=30)
    {
  for(int i=1;i<=r;i++)
   { 
             b[i]=a[r-i+1];
       }
      for(int i=1;i<=r;i++)
      {
      c[i]=c[i]+a[i]+b[i];
      if(c[i]>n-1)
      {
    c[i]%=n;
    c[i+1]++;
    if(i==r)
    k=r+1;
      }
  }
  r=k;
  for(int i=1;i<=r;i++)
  {
      a[i]=c[i];
      c[i]=0;
  }
  step++;
    }
    if(ch())
    cout<<"STEP="<<step;
    else cout<<"Impossible!";
}