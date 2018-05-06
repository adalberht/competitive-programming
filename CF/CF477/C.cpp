#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);\
				cin.tie(0);\
				cout.tie(0)
#define REP(_i, _a) for(int _i = 0; _i < (int)_a; ++_i)
#define FOR(_i, _a, _b) for(int _i = (int)_a; _i <= (int)_b; ++_i)
#define FORD(_i, _a, _b) for(int _i = (int)_a; _i >= (int)_b; --_i)
#define RESET(_a, _value) fill_n(_a,sizeof(_a)/sizeof(_a[0]),_v)
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n';

// DEBUG UTIL
#define DEBUG(args...) { cerr << "> "; \
						 string _s = #args; \
						 replace(_s.begin(), _s.end(), ',', ' '); \
						 stringstream _ss(_s); istream_iterator<string> _it(_ss); \
						 err(_it, args); }

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << ": " << a << " ";
	err(++it, args...);
}

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

int n, m, cl, ce, v;
set<int> elevators;
set<int> stairs;

void test() {

}

void read() {
	cin >> n >> m >> cl >> ce >> v;
	int stair, elevator;
	REP(i, cl) {
		cin >> stair;
		stairs.insert(stair);
	}
	REP(i, ce) {
		cin >> elevator;
		elevators.insert(elevator);
	}
}

ii findNearest(int b, set<int>& candidates) {
	ii nearest = {-1, -1};
	auto it1 = candidates.lower_bound(b);
	if (it1 != candidates.end()) nearest.fi = *it1;
	
	it1 = candidates.lower_bound(b);
	if (it1 != candidates.begin()) {
		--it1;
		nearest.se = *it1;
	}
	return nearest;
}

void solve() {
	int q;
	cin >> q;
	while(q--) {
		int a, b, c, d;

		cin >> a >> b >> c >> d;
		if (a == c) {
			cout << abs(d-b) << endl;
			continue;
		}

		if (a * m + b > c * m + d) {
			swap(a, c);
			swap(b, d);
		}
		int all_elevator = 1e9;
		int all_stair = 1e9;

		ii nearest_elevator = findNearest(b, elevators);
		ii nearest_stair = findNearest(b, stairs);

		if (nearest_elevator.fi != -1) all_elevator = min(all_elevator, abs(b-nearest_elevator.fi)+abs(nearest_elevator.fi-d)+(int)ceil(abs(c-a)/(double)v));
		if (nearest_stair.fi != -1) all_stair = min(all_stair, abs(b-nearest_stair.fi)+abs(nearest_stair.fi-d)+(abs(c-a)/1));

		if (nearest_elevator.se != -1) all_elevator = min(all_elevator, abs(b-nearest_elevator.se)+abs(nearest_elevator.se-d)+(int)ceil(abs(c-a)/(double)v));
		if (nearest_stair.se != -1) all_stair = min(all_stair, abs(b-nearest_stair.se)+abs(nearest_stair.se-d)+abs(c-a));

		cout << min(all_elevator, all_stair) << endl;
	}
}

int main() {
	FAST_IO;
	
	test();

	int TC = 1;
	// cin >> TC;
	FOR(tc, 1, TC) {
		read();
		solve();
	}

	return 0;
}
