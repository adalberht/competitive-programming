#include <bits/stdc++.h>

using namespace std;

void FAST_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

#define REP(_i, _a) for (int _i = 0; _i < _a; ++_i)
#define FOR(_i, _a, _b) for (int _i = _a; _i <= _b; ++_i)
#define FORD(_i, _a, _b) for (int _i = _a; _i >= _b; --_i)
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

const int MAX_N = 1e3 + 5;

class DoubleHash {
    public:
    vector<ll> suf1, suf2, b1, b2;

    ll base1 = 31;
    ll base2 = 37;
    ll mod1 = 1e9+9;
    ll mod2 = 1e9+7;

    DoubleHash(string s) {
      int n = s.length();
      suf1.assign(n + 1, 0);  // suf[n] = 0
      b1.assign(n + 1, 0);
      b1[0] = 1LL;
      b1[1] = base1;
      for (int i = n - 1; i >= 0; --i) {
        suf1[i] = (s[i] + suf1[i + 1] * b1[1]) % mod1;
      }
      for (int i = 2; i <= n; ++i) {
        b1[i] = (b1[i - 1] * b1[1]) % mod1;
      }

      suf2.assign(n + 1, 0);  // suf[n] = 0
      b2.assign(n + 1, 0);
      b2[0] = 1LL;
      b2[1] = base2;
      for (int i = n - 1; i >= 0; --i) {
        suf2[i] = (s[i] + suf2[i + 1] * b2[1]) % mod2;
      }
      for (int i = 2; i <= n; ++i) {
        b2[i] = (b2[i - 1] * b2[1]) % mod2;
      }
    }

    pair<ll, ll> substr(int l, int r) const { // [l, r]
        ll v1 = suf1[l] - suf1[r + 1] * b1[r - l + 1];
        v1 %= mod1;
        v1 += mod1;
        v1 %= mod1;

        ll v2 = suf2[l] - suf2[r + 1] * b2[r - l + 1];
        v2 %= mod2;
        v2 += mod2;
        v2 %= mod2;

        return {v1, v2};
    }

};

string s;
int is_good_character[26];
int k;

bool isGoodCharacter(char c) {
    return is_good_character[c - 'a'];
}

int main()
{
    FAST_IO();

    cin >> s;
    REP(i, 26) {
        char c;
        cin >> c;
        if (c == '1') is_good_character[i] = true;
    }
    cin >> k;

    DoubleHash hash = DoubleHash(s);

    int len = s.length();
    set<pair<ll, ll>> different_substrings;

    REP(i, len) {
        int count_bad_characters = 0;
        FOR(j, i, len-1) {
            if (!isGoodCharacter(s[j])) ++count_bad_characters;
            if (count_bad_characters > k) break;
            different_substrings.insert(hash.substr(i,j));
        }
    }

    cout << different_substrings.size() << endl;

    return 0;
}
