#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

#define newline '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

set<char> characters;
string s;
int main() {

	FAST_IO;
	map<char, int> count;
	cin >> s;

	for (auto c: s) {
		characters.insert(c);
	}

	for (auto c: characters) {
		int first = s.find_first_of(c);
		int last = s.length() - 1 - s.find_last_of(c);
		cout << c << ' ' << first << ' ' << last << newline;
		count[c] = max(first, last) + 1;
	}

	int ans = count[s[0]];
	for (auto c: characters) {
		ans = min(ans, count[c]);
	}

	cout << ans << newline;

	return 0;
}
