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

const int MAX_N = 1e5;

int n;
int arr[MAX_N];
int cop[MAX_N];

void read() {
	cin >> n;
	REP(i, n) {
		cin >> arr[i];
		cop[i] = arr[i];
	}
}

void solve() {
	if (n <= 2) { cout << 0 << endl; return; }
	vector<ii> candidates;
	int i = 0;
		candidates.pb({arr[i+1],arr[i]});
		candidates.pb({arr[i+1],arr[i]+1})	;
		candidates.pb({arr[i+1],arr[i]-1});

		candidates.pb({arr[i+1]+1,arr[i]});
		candidates.pb({arr[i+1]+1,arr[i]+1});
		candidates.pb({arr[i+1]+1,arr[i]-1});

		candidates.pb({arr[i+1]-1,arr[i]});
		candidates.pb({arr[i+1]-1,arr[i]+1});
		candidates.pb({arr[i+1]-1,arr[i]-1});

	int ans = 2e9;
	int cur = 0;
	for (auto candidate: candidates) {
		cur = 0;
		REP(i, n) {
			cop[i] = arr[i];
		}
		cop[0] = candidate.se;
		cop[1] = candidate.fi;
		cur += (cop[0] != arr[0]) + (cop[1] != arr[1]);

		int difference = candidate.fi - candidate.se;
		bool valid = true;
		FOR(i, 2, n-1) {
			if (cop[i] - cop[i-1] == difference) continue;
			else {
				++cur;
				if (cop[i]+1 - cop[i-1] == difference) {
					++cop[i];
				} else if (cop[i]-1 - cop[i-1] == difference) {
					--cop[i];
				} else {
					valid = false;
					break;
				}
			}
		}
		if (valid) {
			ans = min(ans, cur);
		}
	}
	if (ans == 2e9 || ans > n) cout << -1 << endl;
	else cout << ans << endl;
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
