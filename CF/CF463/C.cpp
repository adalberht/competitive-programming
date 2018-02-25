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
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

ll N, A, B;

int main() {
  FAST_IO;

  cin >> N >> A >> B;

  ll a, b;
  a = -1LL;
  b = -1LL;
  for (ll i = 0; i <= N; i++) {
    if (i * A > N) continue;
    if ((N - i * A) % B == 0) {
      ll j = (N - i * A) / B;
      if (i * A + j * B == N) {
        a = i;
        b = j;
        break;
      }
    }
  }
  if (b == -1LL) {
    cout << -1 << '\n';
    return 0;
  }
  if (A == 1LL || B == 1LL) {
    cout << 1;
    for (int i = 2; i <= N; ++i) {
      cout << " " << i;
    }
    cout << endl;
    return 0;
  }
  ll last = 1;
  bool first = true;
  for (ll i = 0LL; i < a; ++i) {
    int hehe = last;
    for (ll j = 0LL; j < A - 1LL; ++j) {
      if (!first) {
        cout << " ";
      } else {
        first = false;
      }
      cout << ++last;
    }
    if (!first) cout << " ";
    cout << hehe;
    ++last;
  }
  for (ll i = 0LL; i < b; ++i) {
    int hehe = last;
    for (ll j = 0LL; j < B - 1LL; ++j) {
      if (!first) {
        cout << " ";
      } else {
        first = false;
      }
      cout << ++last;
    }
    if (!first) cout << " ";
    cout << hehe;
    ++last;
  }
  cout << endl;
  return 0;
}
