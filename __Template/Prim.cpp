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
const int INF = 2e9 + 5;

const int MAX_N = 1e5 + 5;

int N;
bool taken[MAX_N];
vector<vii> adj_list;

priority_queue<ii, vector<ii>, greater<ii> > pq;

void process(int node) {
  taken[node] = true;
  for (auto neighbor: adj_list[node]) {
    int v = neighbor.fi;
    int w = neighbor.se;
    if (!taken[node]) {
      pq.push({w, v});
      process(v);
    }
  }
}

void mst() {
	ll mst_cost = 0LL;
	process(0);
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int w = front.first;
		int u = front.second;
		if (!taken[u]) {
			mst_cost += (ll)w;
			process(u);
		}
	}

	cout << mst_cost << endl;

}

int main() {
	FAST_IO();
	
	int tc = 1;
	REP(_i, tc) {
		// read
    mst();
	}

	return 0;
}
