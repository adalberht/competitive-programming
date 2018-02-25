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

const int MAX_N = 1e3 + 5;

int N;

typedef pair<string, string> ss;

map<string, string> adj;
map<string, int> cnt;

void read() {
	adj.clear();
	cnt.clear();

	cin >> N;
	REP(i, N) {
		string a, b;
		cin >> a >> b;
		adj[a] = b;
		if (cnt.count(a)) {
			++cnt[a];
		} else {
			cnt[a] = 1;
		}
		if (cnt.count(b)) {
			++cnt[b];
		} else {
			cnt[b] = 1;
		}
	}
}

void solve() {
	string start;
	for (auto const& it: cnt) {
		if (it.second == 1 && adj.count(it.first)) {
			start = it.first;
		}
	}
	while (adj.count(start)) {
		cout << " " << start << "-" << adj[start];
		start = adj[start];
	}
	cout << newline;
}

int main() {
	FAST_IO();
	
	int tc = 1;
	cin >> tc;
	REP(_i, tc) {
		read();
		cout << "Case #" << _i+1 << ":";
		solve();
	}

	return 0;
}
