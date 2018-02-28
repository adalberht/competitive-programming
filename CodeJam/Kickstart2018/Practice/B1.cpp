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
#define newline '\n';

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

const int MAX = 18;

ll K;

string s;

string rev(string s) {
	string temp = "";
	FORD(i, s.length() - 1, 0) {
		temp += s[i];
	}
	return temp;
}

string sw(string s) {
	string temp = "";
	for (auto c: s) {
		if (c == '0') temp += "1";
		else temp += "0";
	}
	return temp;
}

void preprocess() {
	s = "0";
	FOR(i, 2, MAX) {
		// cout << s << endl;
		s = s + "0" + sw(rev(s));
	}
	// cout << s.length() << endl;
}

void read() {
	cin >> K;
}

void solve() {
	cout << s[K-1] << newline;
}

int main() {
	FAST_IO();
	
	preprocess();

	int tc = 1;
	cin >> tc;
	REP(_i, tc) {
		read();
		cout << "Case #" << _i+1 << ": ";
		solve();
	}

	return 0;
}
