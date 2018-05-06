/*
Albertus Angga Raharja (adalberht)
1606918401

Problem B - Stol
Tags: Prefix Sum 2D, Largest Rectangle Histogram Area

Generate histogram starting from O(N^2)

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

const int MAX_R = 1e3+5;
const int MAX_C = 1e3+5;

int R, C;
int prefix_sum[MAX_R][MAX_C];
char grid[MAX_R][MAX_C];

bool visited[MAX_R][MAX_C];

int start_r, start_c;

int ans;

bool isValidGrid(int r, int c) {
	if (r > R || c > C) return false;
	return grid[r][c] == '.';
}

int query(int r1, int c1, int r2, int c2) {
	return prefix_sum[r2][c2]
		- prefix_sum[r2][c1-1]
		- prefix_sum[r1-1][c2]
		+ prefix_sum[r1-1][c1-1];
}

int getLargestRectangularPerimeter(const vector<int>& hist) {
	int n = hist.size();
	int max_perimeter = 0;
	stack<int> s;
	s.push(0);
	FOR(c, 1, n) {
		while (!s.empty() && hist[c] <= hist[s.top()]) {
			int minimumHeight = hist[s.top()]; s.pop();
			if (minimumHeight == 0) continue;
			int firstSmallerInLeft = s.top();
			int firstSmallerInRight = c;
			int perimeter = 2 * (minimumHeight+(firstSmallerInRight-firstSmallerInLeft-1));
			max_perimeter = max(max_perimeter, perimeter);
		}
		s.push(c);
	}
	return max_perimeter;
}

vi generateHistogram(int start_r) {
	vi hist = {-1};
	FOR(c, 1, C) {
		int top = start_r;
		int down = R;
		int furthestFromTop = start_r-1;
		while (top <= down) {
			int mid = (top+down)/2;
			if (isValidGrid(mid, c) && query(start_r, c, mid, c) == 0) {
				furthestFromTop = mid;
				top = mid + 1;
			} else {
				down = mid - 1;
			}
		}
		hist.pb(furthestFromTop-start_r+1);
	}
	// cerr << start_r << ": ";
	// FOR (c, 1, C) {
	// 	cerr << hist[c] << " ";
	// }
	// cerr << endl;
	return hist;
}

int main() {
	FAST_IO();
	
	cin >> R >> C;
	FOR(r, 1, R) {
		FOR(c, 1, C) {
			cin >> grid[r][c];
			prefix_sum[r][c] = prefix_sum[r-1][c] + prefix_sum[r][c-1] - prefix_sum[r-1][c-1] + (int)(grid[r][c] == 'X');
		}
	}

	FOR(r, 1, R) {
		ans = max(ans, getLargestRectangularPerimeter(generateHistogram(r))-1);
	}

	cout << ans << endl;

	return 0;
}
