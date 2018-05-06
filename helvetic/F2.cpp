#include <bits/stdc++.h>
#define sz(a) (int) a.size()

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int INF = 1e9 + 1000;
const int MAX = 2e5;

int N, M;
int arr[MAX+5], cnt[MAX+5];
multiset<int> ms;
int sum;

bool check() {
	return ms.empty() ? false : *ms.begin() >= 0;
}

void update(int x, int val) {
	auto it = ms.find(cnt[x]);
	ms.erase(it);

	cnt[x] += val;
	ms.insert(cnt[x]);

	sum += val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i=0; i<N; i++) cin >> arr[i];
	for (int i=1; i<=M; i++) {
		cin >> cnt[i];
		cnt[i] = -cnt[i];

		ms.insert(cnt[i]);
		sum += cnt[i];
	}

	// cout << sum << "\n";

	int ans = INF;
	int i = 0, j = 0;

	while (i < N) {
		// cout << "masuk\n";
		while (j < N && !check()) {
			update(arr[j], 1);
			j++;

			// cout << i << " " << j << " : " << ans << " -- " << get() << "\n";
			if (check()) {
				ans = min(ans, sum);
				break;
			}
		}
		// cout << "keluar\n";

		update(arr[i], -1);
		i++;

		// cout << i << " " << j << " : " << ans << " -- " << get() << "\n";
		if (check()) ans = min(ans, sum);
	}
	
	cout << (ans == INF ? -1 : ans)	 << "\n";
	return 0;
}