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

bool comp(ii a, ii b) {
  if(a.fi == b.fi) return a.se < b.se;
  return a.fi > b.fi;
}

int main() {
  __SUBMIT__;
  int n, k;
  cin >> n >> k;
  vector<ii> c;
  for(int i = 1; i <= n; i++) {
    int cost;
    cin >> cost;
    c.pb(mp(cost, i));
  }
  sort(c, c + n, comp());
  int order[n+5];
  for(int i = 0; i < n; i++) order[i] = -1; // init

  return 0;
}
