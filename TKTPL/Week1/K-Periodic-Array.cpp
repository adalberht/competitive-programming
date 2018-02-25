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
#define FAST_IO ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int MAX_N = 1e2 + 5;
const int MAX_K = 1e2 + 5;

int n, k;

int arr[MAX_N];
int cnt[MAX_K][3];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		++cnt[i % k][arr[i]];
	}

	int ans = 0;
	int maks = n / k;
	for (int i = 0; i < k; ++i) {
		// cout << cnt[i][1] << " " << cnt[i][2] << endl;
		ans += min(maks - cnt[i][1], maks - cnt[i][2]);
	}

	cout << ans << endl;

	return 0;
}
