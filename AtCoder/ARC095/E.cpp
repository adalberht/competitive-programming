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

void test() {

}

void read() {

}

void solve() {
	
}

int n, m;
string grid[15];

pll customHash(string s) {
	ll val1 = 0LL;
	for (int i = 0; i < (int)s.length(); ++i) {
		val1 = ((val1 * 37LL) + s[i]) % (MOD);
	}
	ll val2 = 0LL;
	for (int i = 0; i < (int)s.length(); ++i) {
		val2 = ((val2 * 41LL) + s[i]) % (MOD);
	}
	return {val1, val2};
}

map<string, int> cnt;

bool isPalindrome(string s) {
	map<char, int> countFreq;
	for (auto c: s) {
		if (countFreq.count(c)) countFreq[c] += 1;
		else countFreq[c] = 1;
	}
	int cntOdd = 0;
	for (auto keyValue: countFreq) {
		if (keyValue.se % 2 != 0) ++cntOdd;
	}
	return cntOdd <= 1;
}

int main() {
	FAST_IO;
	
	cin >> n >> m;
	REP(i, n) {
		cin >> grid[i];
		sort(ALL(grid[i]));
		if (cnt.count(grid[i])) ++cnt[grid[i]];
		else cnt[grid[i]] = 1;
	}

	int cntOdd = 0;
	string oddString = "";
	for (auto keyValue: cnt) {
		if (keyValue.se % 2 != 0) {
			++cntOdd;
			oddString = keyValue.fi;
		}
	}

	if (cntOdd == 0 || (cntOdd == 1 && isPalindrome(oddString)))
		cout << "YES\n";
	else 
		cout << "NO\n";

	return 0;
}
