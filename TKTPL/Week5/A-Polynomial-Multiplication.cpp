/*
Albertus Angga Raharja (adalberht)
1606918401

Problem A - Polynomial Multiplication
Tags: FFT

Classical FFT problem.

Issues:
- -1 attempt because of overflow, fixed by changing to 64 bits integer (long long)

*/
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


typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 1e3 + 5;

const double PI = acos(-1);
 
typedef complex<double> base;
 
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}
 
void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res) {
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
    res.resize (n);
    for (size_t i=0; i<n; ++i)
        res[i] = (ll) (fa[i].real() + 0.5);
}
 
vector<ll> num1(50005), num2(50005), num3;

int N;

void read() {
  num1.clear();
  num2.clear();

  cin >> N;

  num1.resize(N+1);
  num2.resize(N+1);

  REP(i, N+1) {
    cin >> num1[i];
  }
  REP(i, N+1) {
    cin >> num2[i];
  }

}

void solve() {
  vector<ll> res;
  multiply(num1, num2, res);
  cout << res[0];
  FOR(i, 1, 2*N) {
    cout << " " << res[i];
  }
  cout << endl;
}

int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    read();
    solve();
  }
}
