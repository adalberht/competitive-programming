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

const int MAX_N = 1e2 + 5;

int n;
string s;
int arr[MAX_N];
vector< set<int> > candidates(105);

int main() {
	FAST_IO();

	cin >> n;
	cin >> s;
	FOR(i, 1, n) {
		if (s[i-1] == 'C') arr[i] = 1;
		if (s[i-1] == 'M') arr[i] = 2;
		if (s[i-1] == 'Y') arr[i] = 3;
	}

	FOR(i, 1, n-1) {
		if (s[i] == s[i-1] && s[i] != '?') {
			cout << "No\n";
			return 0;
		}
	}

	REP(i, 105) {
		candidates[i].insert(1);
		candidates[i].insert(2);
		candidates[i].insert(3);
	}

	int cnt = 1;
	FOR(i, 1, n) {
		if (arr[i] == 0) {
			if (candidates[i].count(arr[i-1])) 
				candidates[i].erase(arr[i-1]);
			if (candidates[i].count(arr[i+1]))
				candidates[i].erase(arr[i+1]);
			cnt *= candidates[i].size();
		}
	}
	if (cnt != 1) cout << "Yes\n";
	else cout << "No\n";




	return 0;
}
