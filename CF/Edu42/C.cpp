#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);\
				cin.tie(0);\
				cout.tie(0)
#define REP(_i, _a) for(int _i = 0; _i < (int)_a; ++_i)
#define FOR(_i, _a, _b) for(int _i = _a; _i <= _b; ++_i)
#define FORD(_i, _a, _b) for(int _i = _a; _i >= _b; --_i)
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

const ll MAX_N = 2e9;

int n;

ll digit(ll num) {
	ll ans = 0LL;
	while (num > 0) {
		num /= 10LL;
		++ans;
	}
	return ans;
}

// Return true if a can be build with omitting some digits in b
bool isConstructable(ll a, ll b) {
	if (a > b) return false;
	if (a == b) return true;
	while (b > 0 && a > 0) {
		if (b % 10 == a % 10) {
			a /= 10LL;
		}
		b /= 10LL;
	}
	return a == 0LL;
}

void solve() {
	cin >> n;
	ll square = 1LL;
	while (square * square <= MAX_N) {
		square += 1;
	}
	assert(digit(1001) == 4);
	assert(digit(1) == 1);
	assert(digit(987) == 3);
	assert(digit(MAX_N) == 10);
	ll ans = 1e9;
	bool flag = false;
	for (ll i = 1LL; i <= square; ++i) {
		if (isConstructable(i * i, n)) {
			ll temp = digit(n) - digit(i * i);
			if (temp < ans) {
				flag = true;
				ans = temp;
			}
		}
	}
	if (flag) cout << ans << endl;
	else cout << -1 << endl;
}

int main() {
	FAST_IO;
	
	int TC = 1;
	// cin >> TC;
	FOR(tc, 1, TC) {
		solve();
	}

	return 0;
}
