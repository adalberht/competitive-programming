#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX = 1e3;

int N, dg[MAX+5];

int main() {
	cin >> N;
	for (int i=0; i<N-1; i++) {
		int u, v;
		cin >> u >> v;
		dg[u]++;
		dg[v]++;
	}

	int ans = 0;
	for (int i=1; i<=N; i++) {
		if (dg[i] == 1) ans++;
	}
	
	cout << ans << "\n";
	return 0;
}