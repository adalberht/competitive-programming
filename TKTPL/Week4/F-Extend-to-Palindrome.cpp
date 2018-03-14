/*
Albertus Angga Raharja (adalberht)
1606918401

Problem F - Extend to Palindrome

Tags: String,KMP

Make a given word to palindrome by adding as few characters as possible.
We just need to match text and it's reversed.


Issues (2x Runtime Error Attempt):
- Constructing KMP table with the precise length, solved by adding +5 index on the array.

Solved using KMP algorithm

*/


#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define REP(_i, _a) for(int _i = 0; _i < _a; ++_i)
#define FOR(_i, _a, _b) for(int _i = _a; _i <= _b; ++_i)
#define FORD(_i, _a, _b) for(int _i = _a; _i >= _b; --_i)
#define RESET(_a, _value) memset(_a, _value, sizeof(_a))
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n'
#define DEBUG(_x) cerr << _x << "\n"

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

struct  KMP {
	string P;
	vi b;
	int m;

	void preProcess() {
		int i = 0, j = -1;
		b[0] = -1;
		while (i < m) {
			while (j >= 0 && P[i] != P[j]) j = b[j];
			++i; ++j;
			b[i] = j;
		}
	}

	KMP(string pattern) {
		P = pattern;
		b.assign(pattern.length() + 5, 0);
		m = pattern.length();
		preProcess();
	}

	int search(string T) {
		int i = 0;
		int j = 0;
		int n = T.length();

		while (i < n) {
			while (j >= 0 && T[i] != P[j]) j = b[j];
			++i; ++j;
			if (j == m || j == n) {
				j = b[j];
				return -1;
			}
		}
		return i - j;
	}

};

string reverse_string(string str) {
	string ret = "";
	for (int i = str.length() - 1; i >= 0; --i) {
		ret += str[i];
	}
	return ret;
}

int main() {
	FAST_IO();
	
	int tc = 1;
	string text;

	while (cin >> text) {
		string reversed_text = reverse_string(text); 
		// DEBUG(reversed_text);
		
		KMP kmp = KMP(reversed_text);
		int idx = kmp.search(text);
		
		if (text == reversed_text) cout << text << endl; // already palindrome
		else cout << text.substr(0, idx) + reversed_text << endl;

	}

	return 0;
}
