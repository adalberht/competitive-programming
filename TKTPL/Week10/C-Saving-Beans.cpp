#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fact(ll n, ll MOD) {
    ll ret = 1;
    for (ll i = 1; i <= n; ++i) {
        ret = (1LL * ret * i) % MOD;
    }
    return ret;
}

ll modExp(ll a, ll b, ll MOD) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    ll ret = modExp(a, b/2, MOD);
    ret = (1LL * ret * ret) % MOD;
    if (b % 2 == 1) ret = (1LL * ret * a) % MOD;
    return ret;
}

ll modularInverse(ll x, ll p) {
    return modExp(x, p-2, p);
}

// Return nCr % p
ll nCr(ll n, ll r, ll p) {
    if (n < r) return 0;
    r = min(r, n - r);
    ll ret = (1LL * modularInverse(fact(n-r, p), p) % p * modularInverse(fact(r, p), p) % p) % p;
    ret = (1LL * ret * fact(n, p)) % p;
    return ret; 
} 

ll nCrModpLucas(ll n, ll r, ll p) {
    if (r == 0) {
        return 1;
    }
    ll ans = 1LL;
    while (n || r) {
            ans = (ans * nCr(n % p, r % p, p)) % p;
            n /= p;
            r /= p;
    }
    return ans;
}

ll N, R, M;

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        cin >> N >> R >> M;
        cout << nCrModpLucas(N+R, R, M) << endl;
    }
}