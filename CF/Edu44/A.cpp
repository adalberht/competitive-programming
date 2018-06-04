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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string format(const string& s, ...) {
    va_list args;
    va_start (args, s);
    size_t len = vsnprintf(NULL, 0, s.c_str(), args);
    va_end (args);
    std::vector<char> vec(len + 1);
    va_start (args, s);
    vsnprintf(&vec[0], len + 1, s.c_str(), args);
    va_end (args);
    return &vec[0];
}

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

int n;
vector<int> arr1;

void read() {
	cin >> n;
	arr1.resize(n/2);
	REP(i, n/2) {
		cin >> arr1[i];
	}
	sort(ALL(arr1));
}

void solve() {
	int ganjil = 0;
	int genap = 0;
	for (int i = 0; i < n / 2; ++i) {
		// cout << 2*i+1 << " " << 2*i+2 << " " << arr1[i] << endl;
		ganjil += max(2*i+1, arr1[i]) - min(2*i+1, arr1[i]);
		genap += max(2*i+2, arr1[i]) - min(2*i+2, arr1[i]);
	}
	cout << min(ganjil, genap) << endl;
}

int main() {
	FAST_IO();

	int TC = 1;
	// cin >> TC;
	FOR(tc, 1, TC) {
		read();
		solve();
	}

	return 0;
}
