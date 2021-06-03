#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

vector<string> vs;
vector<int> pos_ans;
string recur_str, s;


long long recur(int len) {
	if(len >= s.size()) {
		//Uncomment to see some output
		/*
		  if (recur_str == s) {
			for(auto it: pos_ans) {
				cout << it << " ";
			}
			cout << endl;
		}*/

		if (len == s.size())
			return 1;
		else
			return 0;
	}

	long long ret = 0;
	for(int i = 0; i < vs.size(); ++i) {
		if(len + vs[i].size() > s.size()) {
			//break, if vs is sorted based on length
			break; 
		}

		int ok = 1, p = 0;
		for(int j = len; p < vs[i].size(); ++p, ++j) {
			if(vs[i][p] != s[j]) {
				ok = 0;
				break;
			}
			recur_str.push_back(vs[i][p]);
		}

		//pos_ans.push_back(i+1);
		if(ok) {
			ret = (ret + recur(recur_str.size()))%MOD;
		}

		for(int j = 0; j < p; ++j)
			recur_str.pop_back();
		//pos_ans.pop_back();
	}

	return ret%MOD;
}

bool sz_func(string &a, string &b) {
	return (a.size() <= b.size());
}

int main() {
	int n, q;

	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> s;
		vs.push_back(s);
	}

	sort(vs.begin(), vs.end(), sz_func);

	cin >> q;
	for(int i = 0; i < q; ++i) {
		cin >> s;
		pos_ans.clear();
		recur_str.clear();
		cout << recur(0) << endl;
	}

	return 0;
}