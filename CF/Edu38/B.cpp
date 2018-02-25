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
#define FAST_IO  ios_base::sync_with_stdio(false);\
		cin.tie(0);\
		cout.tie(0);

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

const int MAX_N = 1e5 + 5;

int N;

int arr[MAX_N];

int taken[MAX_N];

int main() {
	FAST_IO;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; ++i) {
		int cost1 = abs(arr[i] - 1);
		int cost2 = abs(arr[i] - 1e6);
		if (cost1 < cost2) {
			taken[i] = 1;
		} else {
			taken[i] = 2;
		}
	}
	int maximum_1 = -1;
	int maximum_2 = 1e6;
	for (int i = 0; i < N; ++i) {
		if (taken[i] == 1) {
			maximum_1 = max(maximum_1, arr[i]);
		}
	}
	for (int i = N - 1; i >= 0; --i) {
		if (taken[i] == 2) {
			maximum_2= min(maximum_2, arr[i]);
		}
	}
	cout << max(abs(maximum_1 - 1), abs(maximum_2 - (int)1e6)) << endl;
	return 0;
}
