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

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = 1;
    if(a == b) cout << 1 << '\n';
    else if (b - a < 5) {
        ll ans = 1;
        for (ll i = a + 1; i <= b; ++i) {
            ans = (ans * (i % 10)) % 10;
        }
        cout << ans << '\n';
    }
    else cout << 0 << '\n'; 
	return 0;
}
