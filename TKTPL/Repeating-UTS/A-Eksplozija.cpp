/*
  Albertus Angga Raharja - 1606918401
  Problem A - Eksplozija

  Tags: Ad-Hoc
  
*/
#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ALL(_v) _v.begin(), _v.end()
#define RESET(_a, _v) fill_n(_a, sizeof(_a)/sizeof(_a[0]), _v)
#define REP(_i, _n) for (int _i = 0; _i < (int) _n; _i++)
#define FOR(_i, _a, _b) for (int _i = (int)_a; _i <= (int) _b; ++_i)
#define FORD(_i, _a, _b) for (int _i = (int)_a; _i >= (int) _b; --_i)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll INFLL = 4e18;
const int MAX = 1e6 + 5;

const char bof = '\\';
const char eof ='\0';

bool deleted[MAX];
map<char, char> next_character;
string s;
string p;
string ans;
stack<pair<char, int>> st;

int main() {
	FAST_IO();

	cin >> s;
	cin >> p;
	
	if (p.length() == 1) {
		REP(i, 26) {
			next_character['a' + i] = p[0];
			next_character['A' + i] = p[0];
		}

		REP(i, 10) {
			next_character['0' + i] = p[0];
		}

	} else {
		REP(i, 26) {
			next_character['a' + i] = ';';
			next_character['A' + i] = ';';
		}

		REP(i, 10) {
			next_character['0' + i] = ';';
		}
	}
	

	next_character[bof] = p[0];
	st.push({bof, -1});

	REP(i, p.length() - 1) {
		next_character[p[i]] = p[i+1];
	}
	next_character[p[p.length() - 1]] = eof;


	REP(i, s.length()) {
		char top = st.top().fi;
		st.push({s[i], i});
		if (next_character[top] == s[i] && next_character[s[i]] == eof) {
			stack<pair<char, int>> st2;
			unsigned int cnt = 0;
			int j = p.length() - 1;
			while (!st.empty() && j >= 0) {
				pair<char, int> top = st.top(); st.pop();
				if (top.fi == p[j--]) {
					++cnt;
				}
				st2.push(top);
			}
			// cerr << i << " " << cnt << endl;
			if (cnt == p.length()) {
				while (!st2.empty()) {
					deleted[st2.top().se] = true;
					st2.pop();
				}
			} else {
				while (!st2.empty()) {
					st.push(st2.top());
					st2.pop();
				}
			}
		}
	}




	REP(i, s.length()) {
		if (!deleted[i]) ans += s[i];
	}

	if (ans.length() == 0) cout << "FRULA\n";
	else cout << ans << '\n';

	return 0;
}