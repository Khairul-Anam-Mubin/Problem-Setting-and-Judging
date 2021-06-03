#include<bits/stdc++.h>
using namespace std;
int main()
{

    string a,b,c,d,e;
    int cnt=0;
    cin>>a>>b>>c>>d>>e;
   if(a.length()==5)
   {
       cnt++;
   }
      if(b.length()==5)
   {
       cnt++;
   }
      if(c.length()==5)
   {
       cnt++;
   }
      if(d.length()==5)
   {
       cnt++;
   }
      if(e.length()==5)
   {
       cnt++;
   }
   if(cnt==5)
   {
       cout<<"Mim"<<endl;
   }
   else{
    cout<<"Pocha Dim"<<endl;
   }
}
