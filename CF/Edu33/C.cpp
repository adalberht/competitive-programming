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

int n,m;
vector<ii> cost;
vector< vector<int> > adjList;

int main() {
	FAST_IO;

  cin >> n >> m;
  cost.resize(n+5);
  adjList.resize(n+5);
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    cost.pb(mp(c, i));
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  bool visited[n+5];
  memset(visited, false, sizeof(visited));

  sort(cost.begin(), cost.end());
  ll totalCost = 0LL;
  for (auto element: cost) {
    int node = element.se;
    int cost = element.fi;
    if (!visited[node]) {
      totalCost += cost;
      stack<int> st;
      st.push(node);
      while(!st.empty()) {
        node = st.top(); st.pop();
        visited[node] = true;
        for (auto neighbor: adjList[node]) {
          if (!visited[neighbor]) st.push(neighbor);
        }
      }
    }
  }

  cout << totalCost << endl;

  return 0;
}
