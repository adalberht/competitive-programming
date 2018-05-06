/*
	Albertus Angga Raharja - 1606918401
	Problem F - Classrooms
	Repeating Week 1

	Tags: Greedy
	- Sort by end dates
	- For each event:
		- Greedily try to find if there is an event that will be completed before the start of this event
		- If no, check if we can add a new class (new worker)

	Mistakes:
		- Using set instead of multiset
		- Multiset sorting issues
*/
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

const int MAX_N = 1e3 + 5;


bool comp(const ii& a, const ii& b) {
	if (a.se == b.se) return a.fi < b.fi;
	return a.se < b.se;
}

class ScheduleComparator {
	public:
		bool operator() (const ii& a, const ii& b) {
			return comp(a, b);
		}
};

multiset<int> active_classes;
int n, k;
vii schedules;

int main() {
	FAST_IO;
	
	int TC = 1;
	// cin >> TC;
	FOR(tc, 1, TC) {
		int ans = 0;
		cin >> n >> k;
		int start, end;
		REP(i, n) {
			cin >> start >> end;
			schedules.pb({start, end});
		}
		sort(schedules.begin(), schedules.end(), ScheduleComparator());

		for (auto schedule: schedules) {
			tie(start, end) = schedule;
			auto it = active_classes.lower_bound(-start);
			++ans;
			if (it != active_classes.end()) {
				active_classes.erase(it);
				active_classes.insert(-end-1);
			} else if ((int)active_classes.size() + 1 <= k) {
				active_classes.insert(-end-1);
			} else {
				--ans;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
