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

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 2e9;

const int MAX_N = 1e3 + 5;

string s;

int main() {
	FAST_IO();
	
	cin >> s;
	int len = s.length();
	int first_a_occurence = s.find("a");

	if (first_a_occurence == -1) {
		cout << -1 << endl;
		return 0;
	}

	int last_character = 0;
	FOR(i, first_a_occurence+1, len-1) {
		if (last_character < 25 && s[i] <= 'a' + last_character + 1) {
			s[i] = (char)('a' + ++last_character);
		}
	}

	// cout << last_character << endl;
	// cout << s << endl;

	if (last_character != 25) s = "-1";

	cout << s << endl;

	return 0;
}
