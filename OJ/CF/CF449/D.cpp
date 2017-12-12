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

map<int, int> last;

int arr[1005];

int n, m, c;

int filled = 0;

bool has_chtholly_win() {
  for (int i = 1; i < n; ++i) {
    if (arr[i] < arr[i-1]) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 1; i <= c; ++i) {
    last[i] = ((i) % (n+1))-1;
  }

  int p;
  while (filled < n || !has_chtholly_win()) {
    scanf("%d", &p);
    if (arr[last[p]] != 0 || last[p] >= n) {
      for (int i = 0; i < last[p]; ++i) {
        if (arr[i] == 0 || p < arr[i]) {
          last[p] = i;
          break;
        }
      }
    }
    arr[last[p]] = p;
    last[p] = last[p] + 1;
    printf("%d\n", last[p]);
    fflush(stdout);
    ++filled;
  }

	return 0;
}
