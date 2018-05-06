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

const int MAX_N = 1e5 + 5;
const int MAX_K = 20;

int n, k;
int arr[MAX_N];
vi dist(1 << MAX_K, INF);
vvi adj;
string s;

int toInt(string bin) {
	int ans = 0;
	FORD(i, bin.length() - 1, 0) {
		if (bin[i] == '1')
			ans += 1 << (bin.length() - i - 1);
	}
	return ans;
}

string toBinary(int num, unsigned int len = k) {
	string bin = "";
	while (num > 0) {
		bin =(char)(num % 2 + (int)'0') + bin;
		num /= 2;
	}
	while (bin.length() < len) {
		bin = '0' + bin;
	}
	return bin;
}

void test() {
	assert(toBinary(7) == "111");
	assert(toInt("100") == 4);
	assert(toInt("111") == 7);
}

void read() {
	cin >> n >> k;
	REP(i, n) {
		cin >> s;
		arr[i] = toInt(s);
	}
	adj.resize(1 << k);
}

void solve() {
	REP(i, 1 << k) {
		REP(j, k) {
			adj[i].pb(i ^ (1 << j));
		}
	}

	queue<int> q;
	REP(i, n) {
		q.push(arr[i]);
		dist[arr[i]] = 0;
	}

	while (!q.empty()) {
		int u = q.front(); q.pop();
		
		for (auto v: adj[u]) {
			if (dist[v] == INF) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	int maxDistance = 0;
	int maxValue = 0;
	REP(i, 1 << k) {
		if (dist[i] > maxDistance) {
			maxDistance = dist[i];
			maxValue = i;
		}
	}

	cout << toBinary(maxValue) << endl;

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
