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

string reverse_string(string s) {
	string ans = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += s[i];
	}

	return ans;
}

int main() {
	FAST_IO;

	cin >> s;
	cout << s + reverse_string(s) << endl;

	return 0;
}
