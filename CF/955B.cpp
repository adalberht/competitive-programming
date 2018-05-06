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

const int MAX_N = 1e5 + 5;

string s;
int suffix_sum[MAX_N][26];

bool isPowerOfTwo(int n) {
	FOR(i, 1, 31) {
		if ((1 << i) == n) return true;
	}
	return false;
}

int query(int l, int r, int character) {
	if (l > r) swap(l, r);
	return suffix_sum[l][character] - suffix_sum[r+1][character];
}

int queryDistinctCharacters(int l, int r) {
	int cnt = 0;
	REP(i, 26) {
		if (query(l, r, i) > 0) ++cnt;
	}
	return cnt;
}

int main() {
	
	cin >> s;
	sort(ALL(s));

	DEBUG(s);

	int n = s.length();
	FORD(i, n-1, 0) {
		 REP(j, 26) {
			 suffix_sum[i][j] = suffix_sum[i+1][j];
			 if (s[i]-'a' == j) {
				 ++suffix_sum[i][j];
			 }
		 }
	}

	REP(i, n) {
		DEBUG(i);
		cerr << "		"; DEBUG(queryDistinctCharacters(0, i));
		cerr << "		"; DEBUG(queryDistinctCharacters(i+1, n-1));
		int a = queryDistinctCharacters(0, i);
		int b = queryDistinctCharacters(i+1, n-1);
		if (isPowerOfTwo(a) && isPowerOfTwo(b) && a == b) {
			cout << "Yes" << newline;
			return 0;
		}
	}

	cout << "No" << newline;

	return 0;
}
