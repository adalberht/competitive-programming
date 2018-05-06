#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;


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
#define FAST_IO  ios_base::sync_with_stdio(false)
#define EPS 1e-8

int N, Q;

// This is azure97 (Kak Ayaz)'s implementation of SegmentTree 
struct SegmentTree {
    vvi tree;
    vi arr;
    int n;

    SegmentTree() {
    }

    void set_n(int _n) {
        n = _n;
        arr.resize(n+5);
        tree.resize(4*n+5);
    }

    void build(int id, int l, int r) {
        FOR(i, l, r) {
					tree[id].pb(arr[i]);
				}
				sort(tree[id].begin(), tree[id].end());
				if (l == r) return;
				int m = (l + r) / 2;
				int chld = id << 1;

				build(chld, l, m);
				build(chld + 1, m + 1, r);
    }

    void build() {
        build(1, 1, n);
    }

    int query(int id, int l,  int r, int x, int y, int k) {
        if (x <= l && r <= y) {
						int ans = tree[id].end() - lower_bound(tree[id].begin(), tree[id].end(), k);
            return ans;
        } else {
            int m = (l + r) / 2;
            int chld = id << 1;

            int ret = 0;
            if (x <= m) ret += query(chld, l, m, x, y, k);
            if (y > m) ret += query(chld+1, m+1, r, x, y, k);

            return ret;
        }
    }

    int query(int l, int r, int k) {
        return query(1, 1, n, l, r, k);
    }
};

int main() {
    // C++ Fast I/O
    FAST_IO;

    SegmentTree segment_tree;
    // N elements, Q queries
    cin >> N;

    segment_tree.set_n(N);
    
    for (int i = 1; i <= N; ++i) {
        cin >> segment_tree.arr[i]; 
    }

    segment_tree.build();
    
		ll ans = 0LL;
    FOR(i, 1, N-1) {
			if (segment_tree.arr[i] < i + 1) continue;
			ans += segment_tree.query(i+1, segment_tree.arr[i], i);
		}

		cout << ans << endl;

	return 0;
}
