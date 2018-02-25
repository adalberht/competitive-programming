#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll l,r, x, y, k;

	scanf("%I64d %I64d %I64d %I64d %I64d", &l, &r, &x, &y, &k);
	for(ll i = x; i <= y; i++) {
		if(k*i >= l && k*i <= r) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}

l