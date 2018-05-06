#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define REP(_i, _a) for(int _i = 0; _i < _a; ++_i)
#define FOR(_i, _a, _b) for(int _i = _a; _i <= _b; ++_i)
#define FORD(_i, _a, _b) for(int _i = _a; _i >= _b; --_i)
#define RESET(_a, _value) memset(_a, _value, sizeof(_a))
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n';

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 200000 + 5;

int n;
int arr[MAX_N];

int main() {
	FAST_IO();

	int x = 0;
	cin >> n;
	REP(i, n) {
		cin >> arr[i];
		x = max(x, arr[i]);
	}

	int y = 1;
	REP(i, n-1) {
		int difference = abs(arr[i] - arr[i+1]);
		if (difference > 1) {
			y = difference;
			break;
		} else if (difference == 0) {
			cout << "NO\n";
			return 0;
		}
	}
	FOR(i, 1, n - 1) {
		int difference = arr[i-1] - arr[i];
		if (difference < 0) difference = -difference;
		if (difference == 1) {
			if (y == 1) continue;
			int maks = max(arr[i-1], arr[i]);
			int minim = min(arr[i-1], arr[i]);
			if ((minim % y) == 0 && (maks % y) == 1) {
				cout << "NO\n";
				return 0;
			}
		} else if (difference == 0 || difference != y) {
			// cerr << arr[i] << " " << arr[i-1] << " " << y << endl;
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	cout << x << " " << y << endl;

	return 0;
}