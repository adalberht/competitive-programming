/*
Albertus Angga Raharja (adalberht)
1606918401

Problem A - Automatic Trading

Tags: String, Binary Search, Rabin Karp, LCP, Segment Tree

We have to find the longest common prefix between two suffixes.
In other words, we must find an answer (denoted as ans), where:
s.substring(l, l + ans + 1) == s.substring(r, r + ans + 1)

Process thought:
Approach 1:
We can construct LCP, and then for two queried suffix, we can find both it's index in LCP array.
Answer is RMQ(l, r) where l and r is the index of queried suffix in LCP.
(Not proved, haven't tried since the code will be long)

Approach 2: Binary Search + Rabin Karp (Hashing)
For two given index (l, r), we can perform binary search the answer from (0 to s.length() - r)
Naive approach comparing will cost O(N),
With Rabin-Karp's algorithm, we can do preprocessing and string comparing will only cost O(1)

Issues:
- Buggy implementation with Rabin Karp (MOD and exponent)
- Rabin Karp original algorithm needs us to compare string equivalency one by one if its hash value collides.
If the number of collision is huge, this will cost O(N)
To fix that, we use triple hash. So two strings can be called "equivalent" if three of their hash values are the same.


Total Complexity: O(Q log N) where Q is the number of queries and N is the length of the String
Solved by using Rabin Karp algorithm with triple hashes.

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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int PI = acos(-1.0);
const int INF = 2e9;

const int MAX_N = 1e5 + 5;

const ull MOD = (ull)1e15+37;

string s;
int q;

struct SingleHash {
    vector<int> suf, b;
    int mod;

		SingleHash() {
			SingleHash("", 55, 1e9+7);
		}

    SingleHash(string s, int base = 153, int _mod = 1000000009) {
        int n = s.length();
        suf.assign(n + 1, 0); // suf[n] = 0
        b.assign(n + 1, 0);
        b[0] = 1;
        b[1] = base;
        mod = _mod;
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = (s[i] + (ll)suf[i + 1] * b[1]) % mod;
        }
        for (int i = 2; i <= n; ++i) {
            b[i] = (ll)b[i - 1] * b[1] % mod;
        }
    }

    int substr(int l, int r) const { // [l, r]
        ll v = suf[l] - (ll)suf[r + 1] * b[r - l + 1];
        v %= mod;
        v += mod;
        v %= mod;
        return v;
    }

		bool isEqual(int l1, int r1, int l2, int r2) {
			return substr(l1, r1) == substr(l2, r2);
		}
};

SingleHash hash1;
SingleHash hash2;
SingleHash hash3;

void preProcess() {
	hash1 = SingleHash(s, 53, 1e9 + 7);
	hash2 = SingleHash(s, 57, 1e9 + 7);
	hash3 = SingleHash(s, 59, 1e9 + 7);
}

int query(int a, int b) {
	// Binary Search Length
	int l = 0;
	int r = s.length() - b;
	int ans = -1;
	while (l <= r) {
		int len = (l + r) / 2;
		if (hash1.isEqual(a, a+len, b, b+len) && hash2.isEqual(a, a+len, b, b+len) && hash3.isEqual(a, a+len, b, b+len)) {
			ans = len;
			l = len + 1;
		} else {
			r = len - 1;
		}
	}
	return ans + 1;
}

void read() {
	cin >> s;
	preProcess();
	cin >> q;
}

void solve() {
	REP(i, q) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}

int main() {
	FAST_IO();
	
	int tc = 1;
	// cin >> tc;
	REP(_i, tc) {
		read();
		// cout << "Case #" << _i + 1 << ":";
		solve();
	}

	return 0;
}
