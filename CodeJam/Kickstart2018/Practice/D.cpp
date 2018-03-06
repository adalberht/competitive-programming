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

typedef unsigned long long ull;
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

const int MAX_N = 1e3 + 5;

ll orig_pref[MAX_N];

ll new_pref[MAX_N*MAX_N];

int N, Q;

void read() {
	RESET(orig_pref, 0);
	RESET(new_pref, 0);

	cin >> N >> Q;
	ll a;
	FOR(i, 1, N) {
		cin >> a;
		orig_pref[i] = orig_pref[i-1] + a;
	}
	vi new_arr;
	new_arr.pb(-1);
	FOR(i, 1, N) {
		FOR(j, i, N) {
			new_arr.pb(orig_pref[j] - orig_pref[i-1]);
		}
	}
	sort(ALL(new_arr));
	FOR(i, 1, new_arr.size() - 1) {
		new_pref[i] = new_pref[i-1] + new_arr[i];
	}

}

void solve() {
	REP(i, Q) {
		int l, r;
		cin >> l >> r;
		cout << new_pref[r] - new_pref[l-1] << newline;
	}
}

int main() {
	FAST_IO();
	
	int tc = 1;
	cin >> tc;
	REP(_i, tc) {
		read();
		cout << "Case #" << _i + 1 << ":\n";
		solve();
	}

	return 0;
}
