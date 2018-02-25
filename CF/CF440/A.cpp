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

int arr[10];

int main() {
  FAST_IO;
  cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5];
	for (int i = 0; i < (1 << 6); ++i) {
		int team_1 = 0;
    int team_2 = 0;
    int cnt_team_1 = 0;
		for (int j = 0; j < 6; ++j) {
			if (i & (1 << j)) {
        ++cnt_team_1;
				team_1 += arr[j];
			} else {
				team_2 += arr[j];
			}
    }
		if (cnt_team_1 == 3 && team_1 == team_2) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
