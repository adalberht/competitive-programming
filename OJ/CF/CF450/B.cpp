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
#define FAST_IO ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

ll exp(ll a, int b)
{
  int ans = 1;
  for (int i = 0; i < b; ++i)
  {
    ans *= a;
  }
  return ans;
}

int log_int (int a) {
  for (int i = 0; i <= 6; ++i) {
    if (exp(10, i) >= (ll) a) return i;
  }
  return 0;
}

int main()
{
  ll a, b, c;
  FAST_IO;
  int digit = 10000;

  cin >> a >> b >> c;
  int counter = 1;
  a *= 10;
  while (counter <= digit) {
    // cerr << a/b;
    if (a / b == c) {
      // cerr << endl;
      cout << counter << endl;
      return 0;
    }
    a = a % b;
    if (a < b) a *= 10;
    ++counter;
  }
  cout << -1 << endl;
  return 0;
}
