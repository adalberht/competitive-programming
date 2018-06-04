using ll = long long;
using vb = vector<bool>;
const int INF = 2000000000;
const ll LLINF = 9000000000000000000;
int main() {
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	vb has(n, false);
	int ans = 0, covered = 0;
	for (int i = 0; i < m; ++i) {
		bool cov = false;
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);
			if (!has[j] && x == 0) {
				cov = true;
				has[j] = true;
				covered++;
			}
		}
		if (cov) ans++;
	}
	cout << ((ans <= k && covered == n )? "yes" : "no") << endl;
	return 0;
}