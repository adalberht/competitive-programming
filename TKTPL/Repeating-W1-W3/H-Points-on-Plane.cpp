/*
  Albertus Angga Raharja - 1606918401
  Problem H - Points on Plane
  Repeating Week 1

  Tags: Greedy

*/
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);\
        cin.tie(0);\
        cout.tie(0)
#define REP(_i, _a) for(int _i = 0; _i < (int)_a; ++_i)
#define FOR(_i, _a, _b) for(int _i = (int)_a; _i <= (int)_b; ++_i)
#define FORD(_i, _a, _b) for(int _i = (int)_a; _i >= (int)_b; --_i)
#define RESET(_a, _value) fill_n(_a,sizeof(_a)/sizeof(_a[0]),_v)
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n';

// DEBUG UTIL
#define DEBUG(args...) { cerr << "> "; \
            string _s = #args; \
            replace(_s.begin(), _s.end(), ',', ' '); \
            stringstream _ss(_s); istream_iterator<string> _it(_ss); \
            err(_it, args); }

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << ": " << a << " ";
  err(++it, args...);
}

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 1e3 + 5;

typedef tuple<int, int, int> iii;

bool comp(const iii& a, const iii& b) {
  if (get<0>(a) < get<0>(b)) return true;
  if (get<0>(a) != get<0>(b)) return false;
  if (get<0>(a) % 2 == 0) return get<1>(a) < get<1>(b);
  return get<1>(a) > get<1>(b);
}

int n;
vector<tuple<int, int, int>> points;

int main() {
  FAST_IO;
  
  int TC = 1;
  // cin >> TC;
  FOR(tc, 1, TC) {
    cin >> n;
    int x, y;
    REP(i, n) {
      cin >> x >> y;
      points.pb(make_tuple(x/1000, y, i));
    }
    sort(ALL(points), comp);
    bool first = true;
    for (auto point: points) {
      if (!first) cout << " ";
      else first = false;
      cout << get<2>(point) + 1;
    }
    cout << endl;
  }

  return 0;
}
