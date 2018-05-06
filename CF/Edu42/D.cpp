#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);\
				cin.tie(0);\
				cout.tie(0)
#define REP(_i, _a) for(int _i = 0; _i < (int)_a; ++_i)
#define FOR(_i, _a, _b) for(int _i = _a; _i <= _b; ++_i)
#define FORD(_i, _a, _b) for(int _i = _a; _i >= _b; --_i)
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
typedef priority_queue<int, vi, greater<int>> min_heap;


const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 1e3 + 5;

map<ll, min_heap> m;
set<ll> pq; // store real number which occurence is more than 2 currently
int n;
vector<ll> arr;

void solve() {
	cin >> n;
	arr.resize(n);
	REP(i, n) {
		cin >> arr[i];
		if (!m.count(arr[i])) {
			m[arr[i]] = min_heap();
		}
		m[arr[i]].push(i);
	}
	
	for (auto keys: m) {
		if (keys.second.size() >= 2) {
			pq.insert(keys.first);
		}
	}

	while (pq.size() > 0) {
		int idx;
		ll elem = *pq.begin(); pq.erase(pq.begin());
		if (m[elem].size() >= 2) {
			idx = m[elem].top();
			arr[idx] = -1;
			m[elem].pop();

			idx = m[elem].top();
			arr[idx] *= 2LL;
			m[elem].pop();
			
			if (!m.count(2*elem)) m[2*elem] = min_heap();
			m[2*elem].push(idx);

			if (m[elem].size() >= 2) pq.insert(elem);
			if (m[2*elem].size() >= 2) pq.insert(2*elem);
		}
	}

	int cnt = 0;
	for (auto elem: arr) {
		if (elem == -1) continue;
		++cnt;		
	}

	cout << cnt << endl;
	bool flag = false;
	for (auto elem: arr) {
		if (elem == -1) continue;
		if (flag) cout << " ";
		else flag = true;
		cout << elem;
	}
	cout << endl;
	
}

int main() {
	FAST_IO;
	
	int TC = 1;
	// cin >> TC;
	FOR(tc, 1, TC) {
		solve();
	}

	return 0;
}
