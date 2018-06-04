/*
Albertus Angga Raharja (adalberht)
1606918401

Problem A - Addition Chains
Tags: Iterative Deepening + Greedy

*/

#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

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

const int MAX_N = 1e5;

int N;
vi ans(105);
int depth;

bool dfs(int x) {
	if (x == depth) {
		return (ans[x] == N);
	}
	FOR(i, 0, x) {
		if (ans[x] + ans[i] <= N) {
			int sum = ans[x] + ans[i];
			FOR(k, x + 2, depth) sum *= 2;

			if (sum < N) continue;

			ans[x + 1] = ans[x] + ans[i];
			if (dfs(x+1)) return true;
		}
	}
	return false;
}

void solve() {
	ans.clear();
	ans[0] = 1;

	int sum = 1;  	
	depth = 0;
	while(sum < N) {  
			sum *= 2;  
			depth++;  
	}  

	while(!dfs(0)) ++depth;
	
	cout << ans[0];
	FOR(i, 1, depth) cout << " " << ans[i];
	cout << endl;

}

int main() {
	FAST_IO();

	while (cin >> N && N != 0) {
		solve();
	}

	return 0;
}
