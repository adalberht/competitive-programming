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

ll n, k, A, B;

void read() {
	cin >> n >> k >> A >> B;
}

void solve() {
	ll ans = 0LL;
	ll temp = (n / k) * k;

	if (k == 1LL) {
		cout << A * (n-1) << endl;
		return;
	}

	if (n % k != 0LL) {
		ans += (n - temp) * A;
		n = temp;
	}

	while (n > 1LL && n % k == 0LL && B <= ((n - n/k) * A)) {
		ans += B;
		n /= k;
		if (n % k != 0LL) {
			temp = (n / k) * k;
			ans += (n - temp) * A;
			n = temp;
		}
	} 

	ans += (n-1LL)*A;

	cout << ans << endl;

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
