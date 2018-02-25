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

const int MAX = 1e2;

int n, d;
int arr[MAX];

void read() {
	cin >> n >> d;
	REP(i, n) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
}

void solve() {
	REP(i, n) {
		// a + b = i
		FOR(a, 0, i) {
			int b = i - a;
			b = (n-1) - b;
			int dist = arr[b] - arr[a];
			if (dist <= d) {
				cout << i << endl;
				return;
			}
		}
	}
}

int main() {
	FAST_IO();
	
	int tc = 1;
	// cin >> tc;
	while (tc--) {
		read();
		solve();
	}

	return 0;
}
