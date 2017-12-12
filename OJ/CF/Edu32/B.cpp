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
  int n;
  string s;
  map<char, int> count;

  cin >> n;
  cin >> s;

  for (int i = 0; i < s.length(); ++i) {
    if (!count.count(s[i])) count[s[i]] = 0;
    count[s[i]] += 1;
  }

  cout << min(count['L'], count['R'])*2 + min(count['U'], count['D'])*2 << '\n';

	return 0;
}
