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
const int MAX_N = 1e3;


int n, k;
int arr[MAX_N];
int cnt[3];

int main() {
	FAST_IO;

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		++cnt[arr[i]];
	}

	int ans = 1e9;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] != arr[i%k]) {
			++cur;
		}
	}
	ans = min(ans, cur);
	ans = min(ans, cnt[1]);
	ans = min(ans, cnt[2]);

	cout << ans << endl;

	return 0;
}
