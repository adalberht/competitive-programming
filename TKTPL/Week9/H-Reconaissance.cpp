#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll  inf  = 1e18 + 10;
const ld  prec = .000001;
struct car {
    ll pos;
    ll vel;
};
ld getpos(car c, ld time) {
    return c.pos + c.vel * time;
}
ld getwindow(vector<car>& v, ld time) {
    ld lo = inf;
    ld hi = -inf;
    for(auto& i : v) {
        ld val = getpos(i, time);
        lo = min(lo, val);
        hi = max(hi, val);
    }
    return hi - lo;
}
int main() {
  int n;
  cin >> n;
  vector<car> v(n);
  for(auto& i : v) {
      cin >> i.pos >> i.vel;
  }
  ld lo = 0;
  ld hi = 200001;
  while(hi - lo > prec) {
    ld r = (lo+hi*2)/3;
    ld l = (lo*2+hi)/3;
    ld val1 = getwindow(v, l);
    ld val2 = getwindow(v, r);
    if(val1 < val2) hi = r;
    else lo = l;
  }
  cout << fixed;
  cout.precision(5);
  cout << getwindow(v, lo) << endl;
  return 0;
}