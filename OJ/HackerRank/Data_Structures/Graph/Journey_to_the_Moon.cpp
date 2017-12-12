#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO ios_base::sync_with_stdio(false)

int main() {
    FAST_IO;
    
    int n, p;
    cin >> n >> p;

    vvi adjList;
    adjList.resize(n);
    
    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    bool is_visited[n+5];
    memset(is_visited, false, sizeof is_visited);
    stack<int> dfs;
    vi countries;
    for (int i = 0; i < n; ++i) {
        if (!is_visited[i]) {
            dfs.push(i);
            int cnt_node = 0;
            while (!dfs.empty()) {
                int top = dfs.top(); dfs.pop();
                if (!is_visited[top]) ++cnt_node;
                is_visited[top] = true;
                for (auto neighbor: adjList[top]){
                    if (!is_visited[neighbor]) {
                        dfs.push(neighbor);
                    }
                }
            }
            countries.pb(cnt_node);
        }
    }

    ll ans = 0;
    ll sum = countries[0];
    for (int i = 1; i < countries.size(); ++i) {
        ans += (ll)sum * (ll)countries[i];
        sum += countries[i];
    }
    cout << ans << '\n';
    return 0;
}