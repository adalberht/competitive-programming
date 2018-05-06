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

#define newline '\n';
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false);\
		cin.tie(0);\
		cout.tie(0);

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 0x7FFFFFFF;

const int MAX = 	1e4;

int N, M, S, T; // default S (source) = 1, T (sink) = N
int level[MAX+5];
int cap[MAX+5][MAX+5]; // sum of edge's weight
vi adj[MAX+5];

void init() {
	memset(cap, 0, sizeof cap);
	for (int i=0; i<MAX+3; i++) adj[i].clear();
}

bool bfs() {
	memset(level, -1, sizeof level);
	queue<int> q;
	level[S] = 0;
	q.push(S);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int f : adj[now]) {
			if (level[f] == -1 && cap[now][f] > 0) {
				level[f] = level[now] + 1;
				q.push(f);
			}
		}
	}

	return level[T] != -1;
}

int dfs(int now, int path_cap) {
	if (now == T) return path_cap;

	for (int f : adj[now]) {
		if (level[f] == level[now] + 1 && cap[now][f] > 0) {
			int flow = dfs(f, min(path_cap, cap[now][f]));

			if (flow != -1) {
				cap[now][f] -= flow;
				cap[f][now] += flow;
				return flow;
			}
		}
	}

	return -1;
}

int maxflow() {
	int mxflow = 0;

	while (bfs()) {
		while (true) {
			int flow = dfs(S, INF);
			if (flow == -1) break;
			mxflow += flow;
		}
	}

	return mxflow;
}

int main() {

}