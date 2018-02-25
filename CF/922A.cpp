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
#define FAST_IO  ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

ll X, Y;

int main() {

	cin >> X >> Y;

	int copy_machine = Y-1;
	if (copy_machine > 0 && X > copy_machine && (X - copy_machine) % 2 == 0) {
		copy_machine = X;
	}

	if (copy_machine == X) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}
