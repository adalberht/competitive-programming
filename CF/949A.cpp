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

const int MAX_N = 2e5 + 5;

string s;
int N;

set<int> zebras;
set<int> almost_zebras;

int par[MAX_N];

void impossible() {
	cout << -1 << endl;
	exit(0);
}

int main() {
	FAST_IO();
	
	cin >> s;
	N = s.length();
	REP(i, N) {
		if (s[i] == '0') {
			if (!almost_zebras.empty()) {
				par[i+1] = *almost_zebras.begin();
				almost_zebras.erase(almost_zebras.begin());
			}
			zebras.insert(i+1);
		} else {
			if (zebras.empty()) impossible();
			par[i+1] = *zebras.begin();
			almost_zebras.insert(i+1);
			zebras.erase(zebras.begin());
		}
	}
	if (!almost_zebras.empty()) impossible();
	cout << zebras.size() << endl;
	for (auto zebra : zebras) {
		vi ans;
		int cur = zebra;
		while (par[cur] != 0) {
			// cerr << "#" << cur << endl;
			ans.pb(cur);
			cur = par[cur];
		}
		ans.pb(cur);
		int len = ans.size();
		cout << len;
		FORD(i, len-1, 0) {
			cout << " " << ans[i];
		}
		cout << newline;
	}
	
	return 0;
}
