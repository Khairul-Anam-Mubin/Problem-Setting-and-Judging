#include <bits/stdc++.h>
using namespace std;
 
#define F            first
#define S            second  
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Test         int test;cin >> test;for(int tc = 1; tc <= test; tc++)
 
#define INF9         2147483647
#define INF18        9223372036854775806
#define eps          1e-8 
 
const double pi = 2 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

//int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;  // right , left , up , down
//int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;

const ll mod = 1e9 + 7;

struct BinomialCoefficient {
    vector <vector <long long>> ncr;
    int N , R , flag;
    BinomialCoefficient() {
        flag = 0;
    }
    void Init(int n , int r) {
        N = n , R = r;
        flag = 1;
        ncr.assign(n + 1, {});
        for (int i = 0; i <= n; i++) 
            ncr[i].resize(r + 1);
        if (flag) PreComputeDP();
    }
    void PreComputeDP() {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= min(i , R); j++) {
                if (j == 0 || j == i) {
                    ncr[i][j] = 1;
                } else {
                    ncr[i][j] = ((ncr[i - 1][j - 1] % mod) + (ncr[i - 1][j] % mod)) % mod;
                }
            }
        }      
    }
    template <typename T> T NcR(T n , T r) {
        if (flag) return ncr[n][r] % mod;
        T res = 1;
        if (r > n - r) r = n - r;
        for (T i = 0; i < r ; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }  
} ok;
// Building Prefix array
vector <int> BuildPrefixArray(string pattern) {
    vector <int> pfix(pattern.length()) ;
    pfix[0] = 0 ;
    for (int i = 1 ,j = 0 ; i < pattern.length() ; ) {
        if (pattern[i] == pattern[j]) {
            pfix[i++] = ++j ;
        } else {
            if (j == 0) {
                pfix[i++] = 0 ;
            } else {
                j = pfix[j - 1] ;
            }
        }
    }
    return pfix ;
}

int main() {
    FasterIO
    ok.Init(100000 , 100);
    Test {
        string  a, b , c;
        cin >> a >> b >> c;
        
        ll clen = c.size();
        ll alen = a.size();
        
        ll dp[alen + 1];
        memset(dp , 0 , sizeof(dp));
        char ch = c[0];

        for (int i = 0; i < alen; i++) {
            if(i > 0) dp[i] += dp[i - 1];
            if(a[i] == ch) dp[i]++;
        }
        ll cnt = 0 ;
        ll sum = 0;
        vector <int> pfix = BuildPrefixArray(b) ;
        for (int i = 1 , j = 0 ; i < (ll)a.length() && j < (ll)b.length() ; ) {
            if (a[i] == b[j]) {
                i++ ;
                j++ ;
            } else {
                if (j == 0) {
                    i++ ;
                } else {
                    j = pfix[j - 1] ;
                }
            }
            if (j == (int)b.length()) {
                ll sufq = dp[alen - 1] - dp[i - 1];
                ll preq = dp[i - j - 1];
                //cout << sufq << " "  << preq << "\n";
                if (preq >= clen && sufq >= clen) {
                    sum = sum % mod + (ok.NcR(preq , clen) * ok.NcR(sufq , clen)) % mod;
                    sum %= mod;
                }
                j = pfix[j - 1] ;
                cnt++ ; // Number of occurances..
            }
        }
        cout << sum << "\n"; 
    }
    return 0;
}