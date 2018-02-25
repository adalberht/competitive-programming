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

#define newline '\n';
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false);\
		cin.tie(0);\
		cout.tie(0);

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

string s;

bool is_vowel(char c) {
	return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' || c == 'y';
}

bool contains_two_consecutive_vowel(string s) {
	for (int i = 0; i < s.length() - 1; ++i) {
		if (is_vowel(s[i]) && is_vowel(s[i+1])) {
			return true;
		}
	}
	return false;
}

string f(string s, int cur) {
	if (s.length() == 1) return s;
	if (cur >= s.length()) return "";
	if (is_vowel(s[cur]) && is_vowel(s[cur+1])) {
		return s[cur] + f(s, cur+2);
	}
	return s[cur] + f(s, cur+1);
}

int main() {
	int n;
	cin >> n;

	cin >> s;
	while (contains_two_consecutive_vowel(s)) {
		s = f(s, 0);
	}

	cout << s << endl;
	return 0;
}
