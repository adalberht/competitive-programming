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

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int MAX_N = 360;

int n;
int sum = 0;

int prefix_sum[MAX_N+5];
int arr[MAX_N+5];

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	int ans = sum;
	for (int i = 0; i < n; ++i) {
		int temp = arr[i];
		for (int j = i+1; j < i + n; ++j){
      temp += arr[j%(n+1)];
			ans = min(ans, abs(sum-2*temp));
		}
	}
	cout << ans << endl;
	return 0;
}
