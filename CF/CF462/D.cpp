#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

#define newline '\n';
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

ll p, k;

int main() {

	cin >> p >> k;
	
	int cnt = 0;
	string ans = "";

	while (p != 0) {
		ll q = p / -k;
		ll r = p % -k;
		// cout << q << " " << r << endl;
		if (r < 0) {
			++q;
			r += k;
		}
		p = q;
		if (ans.size() > 0) ans += " ";
		ans += to_string(r);
		++cnt;
	}

	cout << cnt << '\n';
	cout << ans << '\n';

	return 0;
}
