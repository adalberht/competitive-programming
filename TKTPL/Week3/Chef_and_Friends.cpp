#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;

#define REP(_i, _a) for(int _i = 0; _i < _a; ++_i)
#define FOR(_i, _a, _b) for(int _i = _a; _i <= _b; ++_i)
#define FORD(_i, _a, _b) for(int _i = _a; _i >= _b; --_i)
#define RESET(_a, _value) memset(_a, _value, sizeof(_a))
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n'

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

const int MAX_N = 1e3 + 5;

bool mat[MAX_N][MAX_N];
bool color[MAX_N];
bool is_bipartite_graph;
int N, M;
int a, b;

bool bfs(int source) {
  queue<int> q;
  q.push(source);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    FOR(v, 1, N) {
      if (u == v) continue;
      if (mat[u][v] && !color[v]) {
        color[v] = !color[u];
        q.push(v);
      } else if (mat[u][v] && color[v] == color[u]) {
        return false;
      }
    }
  }
  return true;
}

bool isBipartiteGraph() {
  RESET(color, false);
  FOR(i, 1, N) {
    if (!color[i]) {
      if (!bfs(i)) return false;
    }
  }
  return true;
}

void read() {
	RESET(mat, true);

	cin >> N >> M;
	REP(i, M) {
		cin >> a >> b;
		mat[a][b] = mat[b][a] = false;
	}
}

void solve() {
  int first = 0;
  FOR(i, 1, N) {
    FOR(j, 1, N) {
      if (i == j) continue;
      if (mat[i][j]) {
        first = i;
        break;
      }
    }
    if (first > 0) break;
  }
	cout << (isBipartiteGraph() ? "YES" : "NO") << newline;
}

int main() {
	
	int tc;
	cin >> tc;
	while (tc--) {
		read();
		solve();
	}

	return 0;
}
