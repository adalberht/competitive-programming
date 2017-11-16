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
#define FAST_IO  ios_base::sync_with_stdio(false); \
					cin.tie(0); \
					cout.tie(0)
#define EPS 1e-8
#define INF 2e9


int main() {
    int n;
    scanf("%d", &n);
    int arr[n+5];
    int cnt[105];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        ++cnt[arr[i]];
    }
    int last = -1;
    bool same = true; 
    vi track;
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] > 0) {
            if (last == -1) {
                last = cnt[i];
                track.pb(i);
            } else if (last != cnt[i]) {
                same = false;
                break;
            } else {
                track.pb(i);
            }
        }
    }
    if (!same) printf("NO\n");
    else {
        if (track.size() % 2 != 0) {
            printf("NO\n");
        } else {
            printf("YES\n%d %d\n", track[0], track[1]);
        }
    }

    return 0;
}

