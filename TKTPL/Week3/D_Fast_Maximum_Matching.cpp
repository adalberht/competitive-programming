// Credits:
// Hopcroft Karp Implementation here is the same as Ahmad Hasan Siregar's implementation (Reuse)

#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

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
#define newline '\n';

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 5e4 + 5;

// HOPCROFT-KARP MAXIMUM BIPARTITE MATCHING O(E sqrt(V))
const int NIL = 0;

int N, M, P; // N = left vertices, M = right vertices
vector<int> adj[MAX_N]; // store only edges from U to V, 1-indexed
int matchU[MAX_N], matchV[MAX_N];
int dist[MAX_N]; // used only by vertices in U
// NIL is 0

bool bfs() {
    queue<int> q;

    FOR(u,1,N) {
        if (!matchU[u]) {
            dist[u] = 0;
            q.push(u);
        }
        else dist[u] = INF;
    }

    dist[NIL] = INF;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        if (dist[u] < dist[NIL]) {
						REP(indeks, adj[u].size()) {
							int v = adj[u][indeks];
							if (dist[matchV[v]] == INF) {
									dist[matchV[v]] = dist[u] + 1;
									q.push(matchV[v]);
							}
            }
        }
    }

    return dist[NIL] != INF;
}

bool dfs(int u) {
    if (u != NIL) {
				REP(indeks, adj[u].size()) {
					int v = adj[u][indeks];
					if (dist[matchV[v]] == dist[u] + 1) {
							if (dfs(matchV[v])) {
									matchV[v] = u;
									matchU[u] = v;
									return true;
							}
					}
        }

        dist[u] = INF;
        return false;
    }

    return true;
}

int hopcroftKarp() {
	int matching = 0;

	while (bfs()) {
		FOR(u,1,N) {
				if (!matchU[u] && dfs(u))
						matching++;
		}
	}

	return matching;
}

void read() {
	RESET(matchU, false);
	RESET(matchV, false);
	RESET(dist, 0);
	REP (i, MAX_N) {
		adj[i].clear();
	}
	
	cin >> N >> M >> P;
	int a, b;
	REP(i, P) {
		cin >> a >> b;
		adj[a].pb(b);
	}
}

int main() {
	FAST_IO();
	
	int tc = 1;
	// cin >> tc;
	FOR(i, 1, tc) {
		read();
		cout << hopcroftKarp() << endl;
	}

	return 0;
}
