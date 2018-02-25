#include <bits/stdc++.h>

using namespace std;


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

using ll = long long;
using ii = pair<int, int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 1e3 + 5;

const int N = 10000;

bool mat[N];

void read() {
	RESET(mat, true);
}

void solve() {
	int cnt = 0;
	REP(i, N) {
		if (mat[i]) ++cnt;
	}
	cout << cnt << newline;
}

int main() {
	
	int tc = 1;
	cin >> tc;
	while (tc--) {
		read();
		solve();
	}

	return 0;
}
