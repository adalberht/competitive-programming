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
    FAST_IO;
    int q;

    cin >> q;
    while(q--) {
        int n, m, c_road, c_lib;
        cin >> n >> m >> c_lib >> c_road;
        vvi adjList;
        adjList.resize(n+5);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        if (c_lib < c_road) {
            cout << (ll)c_lib * (ll)n << '\n';
        } else {
            bool is_visited[n+5];
            memset(is_visited, false, sizeof is_visited);
            stack<int> dfs;
            ll ans = 0;
            for (int i = 1; i <= n; i++) {
                if (!is_visited[i]) {
                    dfs.push(i);
                    int cnt_node = 0;
                    while (!dfs.empty()) {
                        int top = dfs.top(); dfs.pop();
                        // cerr << top << '\n';
                        if (!is_visited[top]) ++cnt_node;
                        is_visited[top] = true;
                        for (auto neighbor: adjList[top]) {
                            if (!is_visited[neighbor]) dfs.push(neighbor);
                        }
                    }
                    // cout << cnt_node << endl;
                    ans += (ll)c_road * (ll)(cnt_node-1) + (ll)c_lib;
                }
            }
            cout << ans << '\n';
        }
    }
	return 0;
}
