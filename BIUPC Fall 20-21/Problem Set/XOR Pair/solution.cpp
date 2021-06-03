#include<bits/stdc++.h>
using namespace std;
typedef	    long long       ll;

ll PoW(ll a){
    ll s=1;
    for(ll i=1;i<=a;i++) s*=2;
    return s;
}

void solve()
{
    ll a=0,b=0,c=0,n,x,y;
    cin>>n>>x;
    while(n){
        if(n%2==0) a++;
        else b++;
        n/=2;
    }
    while(x){
        x/=2;
        c++;
    }
    a+=(c-(a+b));
    x=PoW(a);
    y=PoW(b);
    cout<<(x*y)/2<<endl;
}

int main(){
//	freopen("input.txt", "r", stdin);
    ll t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}
