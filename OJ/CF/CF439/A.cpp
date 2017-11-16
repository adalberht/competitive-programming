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

map<int, bool> memo;

int main() {
    FAST_IO;
    int n;
    cin >> n;
    int x[n+5], y[n+5];
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        memo[x[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
        memo[y[i]] = true;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int hasil_xor = x[i] ^ y[j];
            if (memo.count(hasil_xor)) {
                ++cnt;
            }
        }
    }
    if (cnt % 2 == 0) cout << "Karen\n";
    else cout << "Koyomi\n";

	return 0;
}
