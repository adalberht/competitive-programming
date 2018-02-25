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

int X, Y, K;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {

	cin >> X >> Y >> K;
	int ans = 0;
	for (int x1 = 0; x1 <= X; ++x1) {
		for (int y1 = 0; y1 <= Y; ++y1) {
			for (int x2 = 0; x2 <= X; ++x2) {
				for (int y2 = 0; y2 <= Y; ++y2) {
					if (gcd(abs(x2-x1), abs(y2-y1)) + 1 == K) {
						++ans;
					}
				}
			}
		}

	}

	cout << ans / 2 << endl;

	return 0;
}
