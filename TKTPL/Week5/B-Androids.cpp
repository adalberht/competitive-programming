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

set<int> taken;
set<int> untaken;

int N;

vector<tuple<int, int, int> > arr;

vector<set<ii> > ranks(3);

priority_queue<ii, vector<ii>, greater<ii> > pq;

int get_tuple_character(int i, tuple<int, int, int> t) {
	if (i == 0) {
		return get<0>(t);
	} else if (i == 1) {
		return get<1>(t);
	} else if (i == 2) {
		return get<2>(t);
	}
	return get<0>(t);
}

void read() {
	cin >> N;
	int x, y, z;
	REP(i, N) {
		cin >> x >> y >> z;
		arr.pb(make_tuple(x, y, z));
		ranks[0].insert({x, i});
		ranks[1].insert({y, i});
		ranks[2].insert({z, i});
		untaken.insert(i);
	}
}

int dist(int node1, int node2) {
	int distX = abs(get<0>(arr[node1]) - get<0>(arr[node2]));
	int distY = abs(get<1>(arr[node1]) - get<1>(arr[node2]));
	int distZ = abs(get<2>(arr[node1]) - get<2>(arr[node2]));
	return min(distX, min(distY, distZ));
}

void process(int node) {
	int cur = node;

	taken.insert(cur);
	untaken.erase(cur);

	for (int i = 0; i < 3; ++i) {
		auto it = ranks[i].lower_bound({get_tuple_character(i, arr[cur]), cur});
		if (it != ranks[i].begin()) {
			--it;
			pq.emplace(dist(cur, it->se), it->se);
		}
		
		it = ranks[i].lower_bound({get_tuple_character(i, arr[cur]), cur});
		if (++it != ranks[i].end()) {
			pq.emplace(dist(cur, it->se), it->se);
		}
	}

	for (int i = 0; i < 3; ++i) {
		ranks[i].erase({get_tuple_character(i, arr[cur]), cur});
	}
}


void solve() {
	ll mst_cost = 0LL;
	process(0);
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int w = front.first;
		int u = front.second;
		if (untaken.count(u)) {
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
		read();
		solve();
	}

	return 0;
}
