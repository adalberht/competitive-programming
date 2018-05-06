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

const int MAX_N = 1e3 + 5;

int n, a, b;
string s;
vi segments;

void solve() {
	cin >> n >> a >> b;
	cin >> s;
	int len = s.length();
	int cnt = 0;
	REP(i, len) {
		if (s[i] == '*') {
			segments.pb(cnt);
			cnt = 0;
		} else {
			++cnt;
		}
	}
	if (cnt > 0) segments.pb(cnt);

	int sum = a + b;
	if (a < b) swap(a, b);
	len = segments.size();
	
	REP(i, len) {
		int segment = segments[i];
		if (a < b) swap(a, b);
		if (a + b == 0) break;
		if (segment % 2 == 0) {
			a -= min(a, segment / 2);
			b -= min(b, segment / 2);
		} else {
			a -= min(a, segment / 2 + 1);
			b -= min(b, segment / 2);
		}
	}
	cout << sum - (a + b) << endl;
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
