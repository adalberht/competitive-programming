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

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

// avoiding overflow of a * b % mod, for mod > 2^32
ull mulMod(ull a, ull b, ull mod) {
	a %= mod, b %= mod;
	if (a < b) swap(a, b);

	ull ret = 0;
	for (; b > 0; b >>= 1, a <<= 1, a = (a >= mod) ? a - mod : a) {
		if (b & 1) {
			ret += a;
			if (ret >= mod) ret -= mod;
		}
	}

	return ret;
}

ull powMod(ull a, ull b, ull mod) {
    // assert(0 <= a && a < n && b >= 0);
    ull ret = 1;
    for (; b; b >>= 1, a = mulMod(a, a, mod))
        if (b & 1) ret = mulMod(ret, a, mod);
    return ret;
}

// n = d * 2^s
bool millerTest(ull n, ull d) {
	ull a = 2 + rand() % (n - 2); // [2, n-1]
	ull x = powMod(a, d, n);
	// a ^ d ≡ 1 (mod n) or a ^ d ≡ -1 (mod n)
	if (x == 1 || x == n - 1) return true;
// find smallest a ^ (d * 2^r) ≡ -1 (mod n)
	while (d != n - 1) {
		x = mulMod(x, x, n);
		d *= 2;

		if (x == n-1) return true;
	}

	return false;
}


// don't forget srand(time(0))
// returns true if n is probably prime
// test will be done k times 
// upper_bound of n <= 2^63 - 1
bool isPrime(ll n, int k) {
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;
	ull d = n - 1;
	while (d % 2 == 0) d /= 2;

	for (int i = 0; i < k; i++)
		if (!millerTest(n, d)) 
			return false;

	return true;
}

ll f(ll x, ll c, ll n) {
	return (mulMod(x, x, n) + c) % n;
}

// don't forget srand(time(0))
// infinite loop if n is prime
// check w/ miller rabin first
ll pollardRho(ll n) {
	if (n == 1LL) return 1LL;
	if (n % 2 == 0) return 2LL; // small optimization
	if (isPrime(n, 3)) return n;

	ll x = 2, y = 2, c = 1, d = 1;

	for (int k = 0; d == 1 || d == n; k++) {
		if (k > 0) {
			x = rand() % n + 1;
			y = x;
			c = rand() % n + 1;
		}

		d = 1;
//              floyd's cycle--finding
		while (d == 1) {
			x = f(x, c, n);	
			y = f(f(y, c, n), c, n);
			d = __gcd(abs(x - y), n);
		}
	}

	return d;
}

ll N;

void read() {
	cin >> N;
}

/*
	Returns pair of {primeFactor, exponent} of a given number
*/
ll primeFactor(ll num) {
	if (isPrime(num, 3)) return num;
	else {
		ll factor = pollardRho(num);
		if (!isPrime(factor, 3)) {
			factor = primeFactor(factor);
		}
		return factor;
	}
}

vector<pair<ll, ll>> factorize(ll N) {
	vector<pair<ll, ll>> answers;
	while (N > 1) {
		ll temp = N;
		ll factor = primeFactor(temp);
		ll exponent = 0;
		while (temp % factor == 0) {
			++exponent;
			temp /= factor;
		}
		answers.pb({factor, exponent});
		N = temp;
	}
  sort(ALL(answers));
	return answers;
}

ll pow(ll a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  ll ret = pow(a, b/2);
  ret *= ret;
  if (b % 2) ret *= a;
  return ret;
}

void permutateAllFactors(unsigned int idx, ll x, ll y, vector<pair<ll, ll>>& factors, ll& ret) {
  if (idx == factors.size()) {
    ret += y*x;
    return;
  }
  for (ll i = 0, a = 1; i <= factors[idx].se; i++, a *= factors[idx].fi) {
    permutateAllFactors(idx+1, x*a, y*((factors[idx].se-i)*2LL+1LL), factors, ret);
  }
}

void solve() {
  vector<pair<ll, ll>> factors = factorize(N);
  vector<ll> allFactors;
  ll ret = 0LL;
  permutateAllFactors(0, 1, 1, factors, ret);
  cout << ret << endl;
}

int main() {
	FAST_IO();

	int TC = 1;
	cin >> TC;
	srand(time(0));
	FOR(tc, 1, TC) {
		read();
    cout << "Case " << tc << ": ";
		solve();
	}

	return 0;
}