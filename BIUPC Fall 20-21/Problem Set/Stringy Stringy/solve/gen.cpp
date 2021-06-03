#include <bits/stdc++.h>
using namespace std;

/*
// Code for in3.txt
int main() {
	int n = 1e4;

	cout << n << endl;
	for(int i = 0; i < n; ++i) {
		cout << 'a' << endl;
	}

	cout << '1' << endl;
	for(int i = 0; i < n; ++i) {
		cout << 'a';
	}
	cout << endl;
	
	return 0;
}*/


/*
// Code for in4.txt
int main() {
	int n = 1e4;

	cout << 26 << endl;
	for(int i = 'a'; i <= 'z'; ++i) {
		cout << char(i) << endl;
	}

	cout << '1' << endl;
	for(int i = 0; i < n; ++i) {
		cout << 'a';
	}
	cout << endl;
	
	return 0;
}
*/


// Code for in5.txt
/*
int main() {
	int n = 1e4;

	cout << 26 << endl;
	for(int i = 'a'; i <= 'z'; ++i) {
		for(int j = 0; j < n; ++j)
			cout << char(i);
		cout << endl;
	}

	cout << 26 << endl;
	for(int i = 'a'; i <= 'z'; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << char(i);
		}
		cout << endl;
	}
	
	return 0;
}
*/


// Code for in6.txt
int main() {
	int n = 1e3;

	cout << n*26 << endl;
	for(int j = 0; j < n; ++j) {
		for(int i = 'a'; i <= 'z'; ++i)
			cout << char(i) << endl;
	}

	cout << n*2 << endl;
	for(int j = 0; j < n; ++j) {
		for(int i = 'a'; i <= 'b'; ++i) {
			cout << char(i) << endl;
		}
	}
	
	return 0;
}