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
const int INF = 2000000000;

const int MAX_V = 2e2 + 5;

int res[MAX_V][MAX_V];
int f; // current flow
int mf; // max flow
int s, t; // source, target
vi p(MAX_V, -1);

void augment(int v, int min_edge) {
	if (v == s) {
		f = min_edge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(min_edge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int EdmondKarp(){
	int totalmf=0;
	while(1){
		f=0;
		vector<int> dist(MAX_V,INF);
		dist[s]=0;
		queue<int> q;
		q.push(s);
		p.assign(MAX_V,-1);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if (u == t) break;
			 for(int v = 0; v < MAX_V; v++) {
				if((res[u][v] > 0 )&& (dist[v]==INF)){
					dist[v] = dist[u]+1;
					q.push(v);
					p[v]=u;
				}
			}
		}
		augment(t,INF);
		if(f==0) break;
		totalmf+=f;
	}
	return totalmf;
}

int main() {
	FAST_IO;

	int n;
	int tc = 1;
	while (cin >> n) {
		if (n == 0) break;
		int c;
		cin >> s >> t >> c;
		--s;
		--t;
		for (int i = 0; i < MAX_V; ++i) {
			for (int j = 0; j < MAX_V; ++j) {
				res[i][j] = 0;
			}
		}

		for (int i = 0; i < c; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			--u;
			--v;
			res[u][v] = w;
			res[v][u] = w;
		}
		cout << "Network " << tc++ << '\n';
		cout << "The bandwidth is " << EdmondKarp() << ".\n\n";
	}

	return 0;
}
