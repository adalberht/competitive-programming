#include <bits/stdc++.h>
#define sz(a) (int) a.size()

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int MAX = 2e5;

int N;
pii arr[MAX+5];
map<pii,int> cnt;

int main() {
	cin >> N;
	for (int i=0; i<N; i++) {
		int a = 0, b = 0, c = 0;
		string s; cin >> s;

		int now = 1;
		a += s[now++] - '0';

		if (s[now] != '+') {
			a = 10 * a + s[now++] - '0';
		}

		now++; // skip +

		b += s[now++] - '0';
		if (s[now] != ')') {
			b = 10 * b + s[now++] - '0';
		}

		now += 2; // skip ) /

		c += s[now++] - '0';
		if (now != sz(s)) c = 10 * c + s[now]++ - '0';

		int p = a + b;
		int q = c;
		int g = __gcd(p, q);
		p /= g;
		q /= g;

		arr[i] = {p, q};
		cnt[{p, q}]++;

		// cout << a << " " << b << " " << c << "\n";
		// cout << p << " " << q << "\n";
	}

	for (int i=0; i<N; i++) cout << cnt[arr[i]] << (i+1 == N ? "\n" : " ");
	return 0;
}