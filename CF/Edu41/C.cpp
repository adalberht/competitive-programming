#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define REP(_i, _a) for(int _i = 0; _i < (int)_a; ++_i)
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
typedef vector<vector<char>> vvc;

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 1e3 + 5;

int n;
vvc boards[4];

int color(const vvc& board, int start) {
	int cur = start;
	int temp = 0;
	REP(i, board.size()) {
		REP(j, board[i].size()) {
			if (board[i][j] != cur) {
				++temp;
			}
			cur = (cur + 1) % 2;
		}
	}
	return temp;
}

int main() {
	FAST_IO();
	
	cin >> n;
	REP(i, 4) {
		boards[i].resize(n);
		REP(j, n) {
			boards[i][j].resize(n);
		}
	}

	REP(k, 4) {
		REP(i, n) {
			REP(j, n) {
				cin >> boards[k][i][j];
				boards[k][i][j] -= (int)'0';
			}
		}
	}

	ll ans = 1e18;
	REP(lt, 4) {
		REP(lb, 4) {
			REP(rt, 4) {
				REP(rb, 4) {
					set<int> s = {lt, lb, rt, rb};
					if (s.size() != 4) {
						// cerr << lt << " " << lb << " " << rt << " " << rb << endl;
						continue;
					}
					REP(start, 2) {
						ll cur = 0LL;
						cur += color(boards[lt], start);
						cur += color(boards[lb], (start + 1) % 2);
						cur += color(boards[rt], (start + 1) % 2);
						cur += color(boards[rb], start);
						ans = min(ans, cur);
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
