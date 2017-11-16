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
#define __SUBMIT__  ios_base::sync_with_stdio(false); \
					cin.tie(0); \
					cout.tie(0);
#define EPS 1e-8

int main() {
    int n;
    scanf("%d", &n);
    int arr[2*n+5];
    for(int i = 0; i < 2*n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + 2*n);
    int cnt = n - 1;
    int indeks = 0;
    int ans = 0;
    while (cnt > 0) {
        ans += arr[indeks+1] - arr[indeks];
        indeks += 2;
        --cnt;
    }
    for(int i = 0; i < 2*n; i++) {
        for (int j = i+1; j < 2*n; j++) {
             cnt = n - 1;
             indeks = 0;
            int cur = 0;
            queue<int> kayak;
            while(cnt > 0) {
                if (indeks != i && indeks != j) {
                    kayak.push(arr[indeks]);
                    if (kayak.size() >= 2) {
                        int besar = kayak.front(); kayak.pop();
                        int kecil = kayak.front(); kayak.pop();
                        cur += max(besar,kecil) - min(besar,kecil);
                        --cnt;
                    }
                }
                ++indeks;
            }
            ans = min(ans, cur);
        }
    }

    printf("%d\n", ans);
}