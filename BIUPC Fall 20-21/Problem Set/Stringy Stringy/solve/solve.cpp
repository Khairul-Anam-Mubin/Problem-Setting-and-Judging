#include<bits/stdc++.h>
#define MAX_LEN 1000100
#define PRIME 31
#define MOD 1000000009
typedef long long ll;
using namespace std;

ll p_pow[MAX_LEN];
void genPow() {
	p_pow[0] = 1;
	p_pow[1] = 31;
	for(int i = 2; i < MAX_LEN-1; ++i)
		p_pow[i] = (p_pow[i-1] * PRIME)%MOD;
}


ll hash_arr[MAX_LEN];
ll Hash(char *s,  int len) {
    ll hashVal = 0;
    for(int i = 0; i < len; ++i) {
        hashVal = (hashVal + (s[i] - 'a' + 1) * p_pow[i])%MOD;
        hash_arr[i] = hashVal;
    }
    return hashVal;
}


ll dp[MAX_LEN];
ll max_len, query_hash, n; 
ll len_s[MAX_LEN], hash_s[MAX_LEN];

ll recur(ll tot_len, ll hash_val) {
	if(tot_len >= max_len) {
		return (hash_val == query_hash);
	}

	if(dp[tot_len] != -1)
		return dp[tot_len];

	ll ret = 0;
	
	for(int i = 0; i < n; ++i) {
		ll new_hash = (hash_val + (hash_s[i] * p_pow[tot_len])%MOD)%MOD;
		
		// GURANTEED FORWARD DFS ONLY WHEN THE STRING MATCHES
		if(new_hash == hash_arr[int(tot_len + len_s[i] - 1)])
			ret = (ret + recur(tot_len + len_s[i], new_hash))%MOD;
	}

	return dp[tot_len] = ret%MOD; 
}


char s[MAX_LEN];

int main() {
	genPow();
	cin >> n;

	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		len_s[i] = strlen(s);
		hash_s[i] = Hash(s, len_s[i]);
	}

	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		scanf("%s", s);
		max_len = strlen(s);
		query_hash = Hash(s, max_len);
		memset(dp, -1, sizeof(dp));

		printf("%lld\n", recur(0, 0));
	}

	return 0;
}