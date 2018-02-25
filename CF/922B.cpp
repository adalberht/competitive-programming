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

int n;

int main() {

	cin >> n;
	int ans = 0;
	for (int a = 1; a <= n; a++) {
		for (int b = a; b <= n; b++) {
			int c = a ^ b;
			if (c < a || c < b || c > n) continue;
			// cerr << a << " " << b << " " << c << endl;
			if (a + b > c && a + c > b && b + c > a) ++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
