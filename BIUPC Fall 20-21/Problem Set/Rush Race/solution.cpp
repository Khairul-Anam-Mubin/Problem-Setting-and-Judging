/***
**      Bismillahir Rahmanir Rahim                
**              ALLAHU AKBAR
**
**     Author: Khairul Anam Mubin (__Broly__)
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
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
 
bool cmp(pair <ll , ll> a , pair <ll , ll> b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
} 
int main() {
    FasterIO
    //Fin;
    //Fout;
    ll r; cin >> r;
    vector <string> names;
    vector <pair <ll , pair <ll , ll>>> v[r];
    vector <ll> tot(r);
    for (int i = 0; i < r; i++) {
        string na; cin >> na;
        ll details; cin >> details;
        names.push_back(na);
        ll sum = 0;
        for (int j = 0; j < details; j++) {
            ll a , b , x;
            cin >> a >> b >> x;
            v[i].push_back(make_pair(a , make_pair(b , x)));
            sum += (b - a + 1) * x;
        }
        tot[i] = sum;
    }
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        ll minute; cin >> minute;
        cout << "position chart at minute " << minute << " :\n";
        vector <pair <ll , ll>> now(r);
        for (int j = 0; j < r; j++) {
            ll last_time = v[j].back().second.first;
            ll sum = (minute / last_time) * tot[j];
            //cout << minute << " " << last_time << " " << minute / last_time << " here\n";
            if (minute % last_time != 0) {
                ll ok = minute % last_time;
                //minute = minute % last_time;
                for (int k = 0; k < v[j].size(); k++) {
                    if (v[j][k].first <= ok && v[j][k].second.first >= ok) {
                        sum += (ok - v[j][k].first + 1) * v[j][k].second.second;
                        break;
                    } else {
                        sum += (v[j][k].second.first - v[j][k].first + 1) * v[j][k].second.second;
                    }
                }
            }
            now[j] = {sum , j};
        }
        sort(now.begin() , now.end(), cmp);
        for (int j = 0; j < r; j++) {
            cout << j + 1 << ". " <<  names[now[j].second] << " " << now[j].first << "\n";
        }
    }
    return 0;
}