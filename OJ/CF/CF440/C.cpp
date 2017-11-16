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
#define FAST_IO ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int MAX_N = 2e5 + 5;

int N;
vi arr;
vi room;
vi last;

int main() {
  FAST_IO;
  cin >> N;
  arr.resize(N+5); 
  last.resize(N+5); 
  room.resize(N+5);
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  int ans = 1;
  room[0] = ans;
  last[1] = 0;
  for (int i = 1; i <= N; ++i) {
    int e = arr[i];
    if (last[room[e]] != e) ++ans;
    room[i] = ans;
    last[ans] = i;
  }
  cout << ans << '\n';
  return 0;
}

