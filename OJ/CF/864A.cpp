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

map<int, int> cards;
int n;

int main() {
    FAST_IO;
    cin >> n;
    for (int i = 1; i <= 100; ++i) cards[i] = 0;
    for (int i = 0; i < n; ++i) {
        int card;
        cin >> card;
        ++cards[card];
    }
    vector<int> ans;
    int last = -1;
    int cnt = 0;
    bool is_all_same = true;
    for (int i = 1; i <= 100; ++i) {
        if (cards[i] != 0) {
            if (last == -1) last = cards[i];
            else if (cards[i] != last) {
                is_all_same = false;
            }
            ans.pb(i);
            ++cnt;
        }
    }
    if (cnt == 2 && is_all_same) {
        cout << "YES\n";
        cout << ans[0] << " " << ans[1] << '\n';
    }
    else cout << "NO\n";
    return 0;
}
