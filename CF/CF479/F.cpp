#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define REP(_i, _a) for(int _i = 0; _i < (int)_a; ++_i)
#define FOR(_i, _a, _b) for(int _i = (int)_a; _i <= (int)_b; ++_i)
#define FORD(_i, _a, _b) for(int _i = (int)_a; _i >= (int)_b; --_i)
#define RESET(_a, _value) fill_n(_a,sizeof(_a)/sizeof(_a[0]),_v)
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n';

// DEBUG UTIL
#define DEBUG(args...) { cerr << "> "; \
						 string _s = #args; \
						 replace(_s.begin(), _s.end(), ',', ' '); \
						 stringstream _ss(_s); istream_iterator<string> _it(_ss); \
						 err(_it, args); }

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << ": " << a << " ";
	err(++it, args...);
}

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 2e5 + 5;

int n;
map<int, int> m;
int arr[MAX_N], LIS[MAX_N], par[MAX_N];

void read() {
	cin >> n;
	REP(i, n) {
		cin >> arr[i];
		par[i] = i;
	}
}

void print(int x) {
	if (par[x] == x) cout << x + 1;
	else {
		print(par[x]);
		cout << " " << x + 1;
	}
}

void solve() {
	REP(i, n) {
		if (m.count(arr[i] - 1)) {
			LIS[i] = LIS[m[arr[i] - 1]] + 1;
			par[i] = m[arr[i] - 1];
		} else {
			LIS[i] = 1;
		}
		m[arr[i]] = i;
	}
	ii ans = {0, 0};
	REP(i, n) {
		if (LIS[i] > ans.fi) {
			ans.fi = LIS[i], ans.se = i;
		}
	}
	cout << ans.fi << endl;
	print(ans.se);
	cout << endl;
}

int main() {
	FAST_IO();

	int TC = 1;
	// cin >> TC;
	FOR(tc, 1, TC) {
		read();
		solve();
	}

	return 0;
}
