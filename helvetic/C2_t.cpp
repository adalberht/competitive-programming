#include <bits/stdc++.h>
#define sz(a) (int) a.size()

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int INF = 1e9 + 10124;
const int MAX = 2e4;

int N, K, P;
int arr[MAX+5];
int dp[MAX+5][55][105];

int solve(int pos, int k, int sum) {
	int &ret = dp[pos][k][sum];

	if (ret == -1) {
		if (pos == N) ret = (k == K ? sum : -INF);
		else if (k == K) ret = -INF;
		else ret = max(solve(pos + 1, k, (sum + arr[pos]) % P), sum + solve(pos + 1, k + 1, arr[pos] % P));
	}

	// cout << pos << " " << k << " " << sum << " -- " << ret << "\n";
	return ret;
}

int main() {
	cin >> N >> K >> P;
	for (int i=0; i<N; i++) cin >> arr[i];

	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, 0) << "\n";
	return 0;
}