#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr[MAX_N];

int n;

int prefix_maximum[MAX_N];
int suffix_minimum[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		prefix_maximum[i] = arr[i];
		suffix_minimum[i] = arr[i];
	}

	for (int i = 0; i < n; ++i) {
		prefix_maximum[i] = max(prefix_maximum[max(i-1, 0)], arr[i]);
	}

	for (int i = n - 1; i >= 0; --i) {
		suffix_minimum[i] = min(suffix_minimum[min(i+1, n -1)], arr[i]);
	}

	// cerr << "Elements: ";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << arr[i] << " ";
	// } cerr << endl;

	// cerr << "Maximums: ";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << prefix_maximum[i] << " ";
	// }	cerr << endl;

	// cerr << "Minimums: ";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << suffix_minimum[i] << " ";
	// } cerr << endl;

	int ans = 0;
	if (arr[0] < suffix_minimum[1]) ++ans;
	for (int i = 1; i < n - 1; ++i) {
		if (arr[i] > prefix_maximum[i-1] && arr[i] < suffix_minimum[i+1]) ++ans;
	}
	if (arr[n-1] > prefix_maximum[n-2]) ++ans;

	cout << ans << '\n';
	return 0;
}