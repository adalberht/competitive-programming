#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector< pair<ll, int> > vli;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false); \
					cin.tie(0); \
					cout.tie(0);
#define EPS 1e-8

int main() {
    ll n, given[5];
    FAST_IO

    cin >> n >> given[0] >> given[1] >> given[2];
    ll baca;
    vli sorted;
    for (int i = 0; i < n; i++) {
        cin >> baca;
        sorted.pb(mp(baca, i));
    }
    sort(sorted.begin(), sorted.end());
    int last_negative = 0;
    int last_positive = n-1;
    bool answer_exist = false;
    ll ans = 0;
    while(last_negative < last_positive) {
        // cout << last_negative << " " << last_positive << endl;
        ll cur = 0;
        bool flag = true;
        int last = 0;
        int kiri = 0;
        int kanan = n-1;
        for (int i = 0; i <= 2; i++) {
            if (given[i] < 0) {
                while(kiri < n && sorted[kiri].se < last) ++kiri;
                if (kiri >= n) {
                    // cout << "flag salah " << i << " " << kiri << " " << kanan << endl;
                    ++last_negative;
                    flag = false;
                    break;
                }
                cur += given[i] * sorted[kiri].fi;
                last = sorted[kiri].se;
            } else {
                while(kanan >= 0 && sorted[kanan].se < last) --kanan;
                if (kanan < 0) {
                    // cout << "flag salah " << i << " " << kiri << " " << kanan << endl;
                    --last_positive;
                    flag = false;
                    break;
                }
                cur += given[i] * sorted[kanan].fi;
                last = sorted[kanan].se;
            }
        }
        if (flag) {
            ans = max(ans, cur);
            answer_exist = true;
            break;
        }
    }
    if (answer_exist) cout << ans << '\n';
    else cout << given[0] * sorted[n-1].fi + given[1] * sorted[n-1].fi + given[2] * sorted[n-1].fi << '\n';
	return 0;
}
