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

const int MAXLOG = 16; // ceil(MAX)

int N;
char str[MAX+5];
int rnk[MAXLOG+5][MAX+5]; // step => sorted by first 2^step chars, rank of suffix with idx i
int tmpSA[MAX+5], SA[MAX+5]; // result [0..N-1]
int cnt[MAX+5]; // number for i-th rank suffix
int step; // total number of chars (2^step) need to sort suffix array

void countingSort(int step, int k) {
    memset(cnt, 0, sizeof cnt);
    REP(i,N) cnt[i + k < N ? rnk[step-1][i+k] : 0]++;

    int sum = 0;
    REP(i,max(300,N)) { // max ascii number
        int t = cnt[i];
        cnt[i] = sum;
        sum += t;
    }

    REP(i,N) tmpSA[cnt[SA[i] + k < N ? rnk[step-1][SA[i]+k] : 0]++] = SA[i];
    REP(i,N) SA[i] = tmpSA[i];
}

void constructSA() {
    REP(i,N) {
        rnk[0][i] = str[i];
        SA[i] = i;
    }

    step = 1;
    for (int k=1; k<N; step++, k*=2) {
        countingSort(step, k);
        countingSort(step, 0);

        int r = rnk[step][SA[0]] = 1;
        // add new rank if current rank of suffix SA[i] != rank of suffix SA[i-1]
        FOR(i,1,N-1) rnk[step][SA[i]] = (rnk[step-1][SA[i]] == rnk[step-1][SA[i-1]] && 
            rnk[step-1][SA[i] + k] == rnk[step-1][SA[i-1] + k]) ? r : ++r;

        if (rnk[step][SA[N-1]] == N) break; // some optimization
    }

    --step;
}

// LCP of suffix x and y O(log N)
// could be used to build LCP array in O(N log N)
int lcp(int x, int y) {
    int ans = 0;
    FORD(k,step,0) {
        if (y >= N) break;
        if (rnk[k][x] == rnk[k][y]) {
            int t = min(1 << k, N - y); // handle corner case
            ans += t;
            x += t;
            y += t;
        }
    }

    return ans;
}

int main() {

  
}