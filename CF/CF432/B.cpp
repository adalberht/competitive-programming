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

ll dist(int x1, int y1, int x2, int y2) {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
  int ax, bx, cx;
  int ay, by, cy;

  	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
  	ll d1 = dist(ax, ay, bx, by);
  	ll d2 = dist(bx, by, cx, cy);
    if(d1 == d2 && (ll)(by-ay)*(cx-bx) != (ll)(cy-by)*(bx-ax)) {
      printf("Yes\n");
      return 0;
    }
    printf("No\n");
    
	return 0;
}
