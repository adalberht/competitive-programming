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

int m;
int arr[300];
bool visited[300];
ll memo[300];

ll dp(int n) {
    memo[0] = 1;
    for (int i = 0; i < m; ++i) {
        for(int j = arr[i]; j <= n; j++) {
            memo[j] += memo[j-arr[i]];
        }
    }
    return memo[n];
}

int main() {
    FAST_IO;

    int n;
    memset(visited, false, sizeof visited);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }
    cout << dp(n) << '\n';
	return 0;
}
