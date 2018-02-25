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

int main() {

  int l = 1;
  int r = 1e6;
  int last = 1;

  bool found = false;
  char response[3];
  while (l != r) {
    int mid = (l + r + 1) / 2;
    printf("%d\n", mid);
    fflush(stdout);

    scanf("%s", response);
    if (strcmp(response, "<") == 0) {
      r = mid - 1;
    }
    else {
      l = mid;
    }
  }

  printf("! %d\n", l);
  fflush(stdout);

	return 0;
}
