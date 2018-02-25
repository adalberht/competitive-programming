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
#define FAST_IO  ios_base::sync_with_stdio(false);\
		cin.tie(0);\
		cout.tie(0);

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

const int MAX_N = 1e6 + 5;

int f(int n) {
	int ans = 1;
	while (n > 0) {
		int rem = n % 10;
		if (rem > 0) ans *= rem;
		n /= 10;
	}
	return ans;
}

int g(int n) {
	if (n < 10) return n;
	return g(f(n));
}

int cnt[MAX_N][10];

void preprocess() {
	for (int i = 1; i <= 1e6; i++) {
		for (int j = 1; j <= 9; j++) {
			cnt[i][j] = 0;
		}
	}
	for (int i = 1; i <= 1e6; i++) {
		int res = g(i);
		for (int j = 1; j <= 9; j++) {
			cnt[i][j] = cnt[i-1][j];
		}
		++cnt[i][res];
	}
}

int main() {
	FAST_IO;
	preprocess();

	int Q;
	int l, r, k;


	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> l >> r >> k;
		cout << (cnt[r][k] - cnt[l-1][k]) << endl;
	}

	return 0;
}
