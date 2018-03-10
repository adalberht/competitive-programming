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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 500 + 5;

char grid[MAX_N][MAX_N];

bool visited[MAX_N][MAX_N];

int R, C;
vii wolves;
vii sheeps;

bool is_valid_grid(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C) return false;
	return grid[r][c] == 'D';
}

void dfs(int r, int c) {
	visited[r][c] = true;
	if (is_valid_grid(r+1, c) && !visited[r+1][c]) dfs(r+1, c);
	if (is_valid_grid(r, c+1) && !visited[r][c+1]) dfs(r, c+1);
	if (is_valid_grid(r-1, c) && !visited[r-1][c]) dfs(r-1, c);
	if (is_valid_grid(r, c-1) && !visited[r][c-1]) dfs(r, c-1);
}

void solve() {
	for (auto wolf: wolves) {
		int r = wolf.fi;
		int c = wolf.se;
		if (!visited[r][c]) dfs(r, c);
	}
	bool exist = true;
	for (auto sheep: sheeps) {
		int r = sheep.fi;
		int c = sheep.se;
		if (visited[r][c]) {
			exist = false;
			break;
		}
	}
	if (!exist) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		REP(i, R) {
			REP(j, C) {
				cout << grid[i][j];
			}
			cout << newline;
		}
	}
}

void read() {
	cin >> R >> C;
	REP(i, R) {
		REP(j, C) {
			cin >> grid[i][j];
			if (grid[i][j] == '.') grid[i][j] = 'D';
			if (grid[i][j] == 'S') {
				sheeps.pb({i, j});
			} else if (grid[i][j] == 'W') {
				wolves.pb({i, j});
			}
		}
	}
}

int main() {
	FAST_IO();
	
	int tc = 1;
	// cin >> tc;
	REP(_i, tc) {
		read();
		solve();		
	}

	return 0;
}
