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

const int MAX_PRIME = 5 * 50000;

bool is_prime[MAX_PRIME];

vi primes;

void test() {

}

void sieve() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[1] = false;
	FOR(i, 2, MAX_PRIME) {
		if (!is_prime[i]) continue;
		primes.pb(i);
		for (int j = i + i; j < MAX_PRIME; j += i) {
			is_prime[j] = false;
		}
	}
}

int N;

void read() {
	sieve();
	cin >> N;
}

void solve() {
	int i = 0;
	deque<int> solution;
	while (i < (int)primes.size() && (int)solution.size() < N) {
		
		if (primes[i] % 5 == 1) {
			solution.pb(primes[i]);
		}
		++i;
		
	}

	for (int i = 0; i < (int)solution.size(); ++i) {
		if (i > 0) cout << " ";
		cout << solution[i];
	}
	cout << endl;
}

int main() {
	srand(time(NULL));
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
