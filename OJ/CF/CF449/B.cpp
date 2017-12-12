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

int mod_exp(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  int ret = mod_exp(a, b/2);
  ret *= ret;
  if (b % 2 == 1) ret *= a;
  return ret;
}

ll reverse_number(ll n) {
  ll temp = n;
  ll ans = 0;
  while (n > 0) {
    ans = (ans * 10) + n % 10;
    n /= 10;
  }
  return ans;
}

int main() {
  ll k, p;

  cin >> k >> p;
  ll current_length = 2;
  ll current = 0;
  ll ans = 0;
  ll num = 1;
  ll exponent = 1;
  while (num <= k) {
    // cerr << num * mod_exp(10, exponent) << " " << reverse_number(num) << endl;
    // cerr << num * mod_exp(10, exponent) + reverse_number(num) << endl;
    ans = (ans + num * mod_exp(10, exponent) + reverse_number(num)) % p;
    ++num;
    if (num == mod_exp(10, exponent)) {
      ++exponent;
    }
  }
  cout << ans << '\n';
	return 0;
}
