/*
Albertus Angga Raharja (adalberht)
1606918401

Problem A - Chef and Friends

This problem is asking whether a given graph can be split into two complete graphs that are connected.
Thinking reversely, if a graph is a complete graph, it's complement graph (graph with edges that are not the member of the original graph) must be empty.
So if a graph can be configured to be two connected complete graphs, the complement graph, the left side of the complete graph must be disjoint graph, and the right one must be disjoint too.
So to check whether it's possible to configure the graph to such way,
We need to check the middle part of the complement of the graph, whether it's a bipartite graph or not.

Solved by using bipartite check algorithm..
My first and second attempt are wrong because of a wrong and buggy implementation of the bipartite check.

*/

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
