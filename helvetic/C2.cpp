#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dp[20005][55][105];
int arr[20005];
int n, k, p;

int solve(int idx, int part, int mo) {
	if (idx >= n && part == 0) {
		return 0;
	}
	if (part < 0 || (idx >= n && part > 0)) {
		return -INF;
	}

	int &ret = dp[idx][part][mo];

	ret = max(solve(idx + 1, part, (mo + arr[idx]) % p),
						mo + solve(idx + 1, part - 1, 0));

	printf("%d %d %d : %d\n", idx, part, mo, ret);
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &k, &p);



	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int ans = solve(0, k, 0);

	printf("%d\n", ans);
	return 0;
}