#include <bits/stdc++.h>

using namespace std;

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

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 1e3 + 5;

vector< set<int> > adj_list(MAX_N);
vector< vector<int> > reverse_adj_list(MAX_N);
int dist[MAX_N][MAX_N];
vi dist1(MAX_N, INF);
vi p(MAX_N);
bool visited[MAX_N];

int V, E;
int s, t;

int dijkstra(int s, int t) {
	for (int i = 0; i < MAX_N; ++i) dist[s][i] = INF;
	dist[s][s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto neighbor: adj_list[u]) {
			if (dist[s][neighbor] == INF) {
				dist[s][neighbor] = dist[s][u] + 1;
				p[neighbor] = u;
				q.push(neighbor);
			}
		}
	}
	int cur = t;
	visited[s] = true;
	while (cur != s) {
		visited[cur] = true;
		cur = p[cur];
	}
	return dist[s][t];
}

int dijkstra1(int s, int t) {
	int v = dist1.size();
	for (int i = 0; i < v; ++i) dist1[i] = INF;
	dist1[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto neighbor: adj_list[u]) {
			if (dist1[neighbor] == INF) {
				dist1[neighbor] = dist1[u] + 1;
				p[neighbor] = u;
				q.push(neighbor);
			}
		}
	}
	int cur = t;
	visited[s] = true;
	while (cur != s) {
		visited[cur] = true;
		cur = p[cur];
	}
	return dist1[t];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> V >> E >> s >> t;
	int a, b;
	REP(i, E) {
		cin >> a >> b;
		adj_list[a].insert(b);
		adj_list[b].insert(a);
	}

	FOR(i, 1, V) {
		dijkstra(i, t);
	}

	set<ii> pairs;
	int ans = 0;
	FOR(i, 1, V) {
		FOR(j, i+1, V) {
			if (dist[i][j] > 1 && (dist[s][i] + 1 + dist[j][t] >= dist[s][t] && dist[s][j] + 1 + dist[i][t] >= dist[s][t])) {
				pairs.insert({min(i,j), max(i,j)});
				++ans;
			}
		}
	}
	
	cout << pairs.size() << endl;
	// for(auto cur: pairs) {
	// 	cout << cur.first << " " << cur.second << endl;
	// }
	return 0;
}
