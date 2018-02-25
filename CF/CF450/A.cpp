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
const int MAX_N = 1e5+5;


int N;

int x[MAX_N], y[MAX_N];

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }

  int countLeft = 0;
  int countRight = 0;
  for (int i = 0; i < N; ++i) {
    if (x[i] < 0) ++countLeft;
    if (x[i] > 0) ++countRight;
  }
  if (countLeft <= 1 || countRight <= 1) printf("Yes\n");
  else printf("No\n");

  return 0;
}
