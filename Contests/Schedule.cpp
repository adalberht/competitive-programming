#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); \
				cin.tie(0); \
				cout.tie(0)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(_v)             _v.begin(), _v.end()
#define sz(_v)              (int) _v.size()
#define first(_obj)         (*_obj.begin())
#define last(_obj)          (*prev(_obj.end()))
#define FIND(_obj, _val)    (_obj.find(_val) != _obj.end())
#define RESET(_a, _v)       fill_n(_a,sizeof(_a)/sizeof(_a[0]),_v)
#define REP(_i, _n)         for (int _i = 0; _i < (int) _n; _i++)
#define FOR(_i, _a, _b)     for (int _i = (int) _a; _i <= (int) _b; _i++)
#define FORD(_i, _a, _b)    for (int _i = (int) _a; _i >= (int) _b; _i--)
#define FORIT(_it, _obj)    for (auto _it = _obj.begin(); _it != _obj.end(); _it++)

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

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vi = vector<int>;
using vii = vector<pii>;
using vs = vector<string>;

const int DR[] = {-1, 0, 1, 0};
const int DC[] = {0, -1, 0, 1};
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = 1073741823;
const ll INFLL = 4e18;
const int MAX = 6;

int order[] = {2, 1, 0, 3, 4, 5};
int sch[4][2][6];

void read() {
	REP(i,4)
		REP(t,2) {
			FORD(k,2,0) {
				cin >> sch[i][t][k];
				// sch[i][t][k] = 0;
			}
			FOR(k,3,5) cin >> sch[i][t][k];
		}
}

bool intersect(int a, int b, bool t) { // check b inside a
	bool flag = true;

	REP(k,6) {
		if (sch[b][t][k] == sch[a][0][k]) continue;
		else if (sch[b][t][k] < sch[a][0][k]) { // before start
			flag = false;
			break;
		}
		else if (sch[b][t][k] > sch[a][0][k]) break; // after start
	}

	REP(k,6) {
		if (sch[b][t][k] == sch[a][1][k]) continue;
		else if (sch[b][t][k] > sch[a][1][k]) { // after end
			flag = false;
			break;
		}
		else if (sch[b][t][k] < sch[a][1][k]) break; // before end
	}

	return flag;
}

void solve() {
	REP(i,3) {
		if (intersect(i, 3, 0) || intersect(i, 3, 1) || intersect(3, i, 0) || intersect(3, i, 1)) {
			cout << "COLLIDE\n";
			return;
		}
	}

	cout << "OK\n";
}

int main() {
	FAST_IO;
	int TC = 1; cin >> TC;
	FOR(tc,1,TC) {
		read();
		cout << "Case #" << tc << ": ";
		solve();
	}
}