/*
	Albertus Angga Raharja
	1606918401

	Problem B - SAM I AM
	Classical Minimum Vertex Cover,
	Construct bipartite graphs where U = set of row number, V = set of column numbers
	There is an edge from u element U and v element V if there is an enemy in grid (u, v)

	Run Hapcroft Karp to get maximum matching, the answer is maximum matching.
	Vertex covers can be derived from running alternating path.

	12 Run Time Error attempt because of silly mistake :(
	Forgot to change Hopcroft Karp template variabel,
	It should be: FOR(u, 1, R), I changed the upper one and forgot to change in the solve() part,
	So it's still FOR(u, 1, N).
*/

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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 1e4 + 5;

const int NIL = 0;
// NIL is 0

int R, C, N; // N = left vertices, M = right vertices
vector<int> adj[MAX_N]; // store only edges from U to V, 1-indexed
int matchU[MAX_N], matchV[MAX_N];
int dist[MAX_N]; // used only by vertices in U

bool reading = true;

// Used to determine Vertex Covers
bool visitedU[MAX_N];
bool visitedV[MAX_N];

bool bfs() {
    queue<int> q;

    FOR(u,1,R) {
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
						for (auto v: adj[u]) {
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
				for (auto v: adj[u]) {
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

void alternate(int source) {
	if (source != NIL) {
		queue<int> s;
		s.push(source);
		while (!s.empty()) {
			int u = s.front(); s.pop();
			visitedU[u] = true;
			for (auto v: adj[u]) {
				if (!visitedV[v]) {
					visitedV[v] = true;
					if (matchV[v] != NIL) {
						s.push(matchV[v]);
					}
				}
			}
		}
	}
}


void reset() {
	RESET(matchV, 0);
	RESET(matchU, 0);
	RESET(dist, 0);

	RESET(visitedU, false);
	RESET(visitedV, false);

}

int r, c;

void read() {
	cin >> R >> C >> N;
	if (R == 0 && C == 0 && N == 0) {
		reading = false;
		return;
	}

	REP(u, R+1) {
		adj[u].clear();
	}

	REP(i, N) {
		cin >> r >> c;
		adj[r].pb(c);
	}
}


void solve() {
	int matching = 0;

	// Get Maximum Matching
	while (bfs()) {
		FOR(u,1,R) {
				if (!matchU[u] && dfs(u))
						matching++;
		}
	}

	FOR(u, 1, R) {
		if (!matchU[u] && !visitedU[u]) {
			alternate(u);	
		}
	}
	
	cout << matching;
	FOR(u, 1, R) {
		if (!visitedU[u]) {
			cout << " r" << u;
		}
	}
	FOR(v, 1, C) {
		if (visitedV[v]) {
			cout << " c" << v;
		}
	}
	cout << endl;

}


int main() {
	FAST_IO();
	
	while (reading) {
		reset();
		read();
		if (!reading) break;
		solve();
	}

	return 0;
}
