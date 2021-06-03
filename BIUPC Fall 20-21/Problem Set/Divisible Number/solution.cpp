#include<bits/stdc++.h>
using namespace std;
typedef	    long long       ll;

int main(){
    ll c,i,t,x;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        c=0;
        for(i=0;i<(ll)s.size();i++){
            c+=s[i]-'0';
            x=s[i]-'0';
        }
        if(c%9==0 and x%2==0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
