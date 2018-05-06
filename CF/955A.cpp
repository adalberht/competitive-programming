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

int hh, mm;
int H, D, C, N;

bool isAtDiscountTime(int hh, int mm) {
	return (hh*60+mm) >= 20*60 && (hh*60+mm) <= 23*60+59;
}

int getDifferenceToDiscountTime(int hh, int mm) {
	return 20*60 - (hh*60 + mm);
}

double queryPrice(int H, int N, int C, bool isInDiscountTime) {
	double cost = (double)C;
	if (isInDiscountTime) cost *= 0.8;
	return ceil((double)H/N)*cost;
}

int main() {
	
	cin >> hh >> mm;
	cin >> H >> D >> C >> N;
	cout << fixed << setprecision(4);
	if (isAtDiscountTime(hh, mm)) {
		cout << queryPrice(H, N, C, true) << endl;
		return 0;
	}

	DEBUG(getDifferenceToDiscountTime(hh, mm));

	double waitForDiscountPrice = queryPrice(
		getDifferenceToDiscountTime(hh, mm) * D + H,
		N,
		C,
		true
	);

	double buyNow = queryPrice(H, N, C, false);

	cout << min(waitForDiscountPrice, buyNow) << endl;

	return 0;
}
