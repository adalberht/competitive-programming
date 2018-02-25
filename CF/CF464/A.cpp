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

const int MAX_N = 5e3 + 5;

int n;

int arr[MAX_N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (arr[arr[arr[i]]] == i) ++cnt;
	}
	if (cnt > 0) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
