#include <bits/stdc++.h>

using namespace std;

long long arr[100005];
long long pref[100005];
int n, p;

int main() {
	scanf("%d %d", &n, &p);

	for (int i = 0; i < n; i++) scanf("%I64d", &arr[i]);

	for (int i = 0; i < n; i++) {
		pref[i] = arr[i];
		if (i) pref[i] += pref[i - 1];
	}

	long long ans = 0;

	for (int i = 0; i < n - 1; i++) {
		long long left = (pref[i] % p);
		long long right = (pref[n - 1] - pref[i]) % p;

		ans = max(ans, left + right);
	}

	printf("%I64d\n", ans);
	return 0;
}