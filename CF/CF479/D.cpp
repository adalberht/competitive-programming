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
typedef unsigned long long ull;

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

set<ull> nums;
map<ull, vector<ull>> adj;

set<ull> visited;

unordered_map<ull, ull> path;

int n;

void read() {
	cin >> n;
	ll baca;
	REP(i, n) {
		cin >> baca;
		nums.insert(baca);
	}
	for (auto num: nums) {
		if (nums.count(2 * num)) {
			adj[num].pb(num * 2);
		}
		if (num % 3 == 0 && nums.count(num / 3)) {
			adj[num].pb(num / 3);
		}
	}
}

void dfs(ull state) {
	// DEBUG(state);
	visited.insert(state);
	for (auto neighbor: adj[state]) {
		if (!visited.count(neighbor)) {
			path[state] = neighbor;
			dfs(neighbor);
		}
	}
}

void solve() {
	for (auto num: nums) {
		path.clear();
		visited.clear();

		// DEBUG(num);

		dfs(num);

		bool valid = true;
		for (auto num: nums) {
			if (!visited.count(num)) {
				valid = false;
				break;
			}
		}

		if (valid) {
			ull cur = num;
			cout << cur;

			while (path.count(cur)) {
				cur = path[cur];
				cout << " " << cur;
			}
			cout << endl;
			return;
		}
	}
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
