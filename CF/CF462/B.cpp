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

int loops[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int k;


int main() {
  FAST_IO;

  cin >> k;
  
  ll ans = 0;
  for (int i = 0; i < 18; ++i) {
  	if (k >= 2) {
  		ans = ans * 10LL + 8;
  		k -= 2;
  	} else if (k > 0) {
  		ans = ans * 10LL + 4;
  		--k;
  	}
  }

  if (k == 0) cout << ans << '\n';
  else cout << -1 << endl;


  cout << (ans <= 1e18 ? "true" : "false") << endl;

  return 0;
}
