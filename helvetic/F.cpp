#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX = 100;

int N, M;
int arr[MAX+5], k[MAX+5];
int cnt[MAX+5];


int main() {
	cin >> N >> M;
	for (int i=0; i<N; i++) cin >> arr[i];
	for (int i=1; i<=M; i++) cin >> k[i];

	for (int i=0; i<N; i++) {
		for (int j=i; j<N; j++) {
			memset(cnt, 0, sizeof cnt);

			for (int k=i; k<=j; k++) cnt[arr[k]]++;
			// cout << i << " -- " << j << ": "; for (int i=1; i<=M; i++) cout << cnt[i] << " "; cout << "\n";

			bool flag = true;
			for (int i=1; i<=M; i++) 
				if (cnt[i] != k[i]) {
					flag = false;				
					break;
				}

			if (flag) {
				// cout << i << " -- " << j << "\n";
				cout << "YES\n";
				return 0;
			}
		}
	}

	cout << "NO\n";
	return 0;
}