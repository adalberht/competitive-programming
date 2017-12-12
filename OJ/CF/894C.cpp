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

int m;
set<int> s;


int main() {
  FAST_IO;

  cin >> m;
  int a;

  for (int i = 0; i < m; ++i) {
    cin >> a;
    s.insert(a);
  }

  int gcd = 1;
  for (auto elem: s) {
    gcd = __gcd(gcd, elem);
  }

  if (gcd != s[0]) cout << '-1' << endl;

	return 0;
}
