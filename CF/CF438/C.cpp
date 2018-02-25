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

const int MAX_N = 1e5;
const int MAX_K = 4;

int n, k;
int sum[MAX_K+5];
bool knows[MAX_N+5][MAX_K+5];

int main() {
    FAST_IO;
    
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            cin >> knows[i][j];
            if (knows[i][j]) ++sum[j];
        }
    }
    
    cout << "NO\n";
	return 0;
}
