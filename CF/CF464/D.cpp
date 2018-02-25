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


string s1;
string s2;

set<char> ss1;
set<char> ss2;

int main() {
	int n;
	cin >> n;
	cin >> s1 >> s2;
	for (auto c: s1) {
		ss1.insert(c);
	}
	for (auto c: s2) {
		if (!ss1.count(c))
			ss2.insert(c);
	}
	if (ss2.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	int cnt = 0;
	auto it1 = ss1.begin();
	auto it2 = ss2.begin();
	if (ss1.size() < ss2.size()) swap(ss1, ss2);
	cout << ss1.size() + ss2.size() -1  << endl;
	while (cnt < ss1.size() + ss2.size() - 1) {
		char c1 = *it1;
		char c2 = *it2;
		if (cnt % 2 == 0) {
			cout << c1 << " " << c2 << endl;
			++it1;		
		} else {
			cout << c2 << " " << c1 << endl;
			++it2;
		}
		++cnt;
	}
	return 0;
}
