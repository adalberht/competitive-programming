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
#define MOD 998244353

ll permut(int n, int k) {
    int ans = 1;
    for(int i = k + 1; i <= n; ++i) {
        ans = (ans * i) % MOD;
    }
    return ans;
}

ll combin(int n, int k) {
    int ans = permut(n, k);
    for (int i = 1; i <= k; ++i) {
        ans /= i;
    }
    return ans;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    ll ab = 1;
    for (int i = 0; i <= min(a,b); ++i) {
        ab += (combin(min(a,b), i) * permut(max(a,b), i)) % MOD;
    }
    ll ac = 1;
    for (int i = 0; i <= min(a, c); ++i) {
        ac += (combin(min(a,b), i) * permut(max(a,c), i)) % MOD; 
    }

    ll bc = 1;
    for (int i = 0; i <= min(b, c); ++i) {
        ac += (combin(min(b,c), i) * permut(max(b,c), i)) % MOD; 
    }
    cout << ab << " " << ac << " " << bc << '\n';
    ll ans = ab;
    ans = (ans * ac) % MOD;
    ans = (ans * bc) % MOD;
    cout << ans << '\n';
	return 0;
}
