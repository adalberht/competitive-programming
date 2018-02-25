#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false)
#define EPS 1e-8

map<char, int> cnt;
int n;

void reset_cnt() {
    for (int i = 0; i < 26; ++i) {
        cnt[(char)((int)'a' + i)] = 0;
    }
}

int count_distinct() {
    int temp = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[(char)((int)'a' + i)] != 0) ++temp;
    }
    return temp;
}

bool is_uppercase(char c) {
    return (int)'A' <= (int)c && (int)c <= (int)'Z';
}

int main() {
    FAST_IO;
    cin >> n;
    string s;
    cin >> s;
    int maks = 0;
    int cur = 0;
    reset_cnt();
    for (int i = 0; i < n; ++i) {
        if (!is_uppercase(s[i])) {
            ++cnt[s[i]];
            maks = max(maks, count_distinct());
        } else {
            reset_cnt();
        }
    }
    cout << maks << '\n';
    return 0;
}
