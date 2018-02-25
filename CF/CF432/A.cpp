#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define __SUBMIT__  ios_base::sync_with_stdio(false); \
					cin.tie(0); \
					cout.tie(0);
#define EPS 1e-8

int main() {
  int n, k, t;

  scanf("%d %d %d", &n, &k, &t);
  if (t < k) printf("%d\n", t);
  else if(t <= n) printf("%d\n", k);
  else printf("%d\n", k-t%n);

	return 0;
}
