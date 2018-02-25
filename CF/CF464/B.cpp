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

const int MAX_K = 1e5 + 5;

ll N, K;

ll arr[MAX_K];

int main() {
	FAST_IO;
	cin >> N >> K;
	ll maximum_hamsters = -1LL;
	ll ans = -1;
	for (int i = 0; i < K; ++i) {
		cin >> arr[i];
		ll box = N / arr[i];
		ll number_of_hamsters = box * arr[i];
		if (number_of_hamsters > maximum_hamsters) {
			maximum_hamsters = number_of_hamsters;
			ans = i;
		}
	}
	cout << ans+1 << " " << maximum_hamsters/arr[ans] << '\n';
	
	return 0;
}
