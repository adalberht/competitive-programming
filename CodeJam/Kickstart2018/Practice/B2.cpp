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

map<ll, bool> memo;

void read() {
	cin >> K;
}

bool isPangkatDua(ll k) {
	if (k == 1) return true;
	while (k > 1) {
		if (k % 2 != 0) return false;
		k /= 2;
	}
	return true;
}

ll pangkatDuaTerdekat(ll k) {
	FORD(i, 63, 0) {
		if ((1 << i & k) != 0) {
			return (1 << i);
		}
	}
}

bool query(ll K) {
  if (K == 1) {
		return 0;
	}
	if (memo.count(K)) {
		return memo[K];
	}
	if (isPangkatDua(K)) {
		return 0;
	}
	ll d = pangkatDuaTerdekat(K);
	// cout << "Pangkat dua terdekat dari: " << K << " " << d << endl;
	bool &ret = memo[K];
	return ret = !query(d - (K - d));
}

void solve() {
	cout << (query(K) ? '1' : '0') << endl;
}

int main() {
	FAST_IO();

	int tc = 1;
	cin >> tc;
	REP(_i, tc) {
		read();
		cout << "Case #" << _i+1 << ": ";
		solve();
	}

	return 0;
}
