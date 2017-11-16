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
    
    cin >> n;
    vvi adjList;
    adjList.resize(n+5);
    for (int i = 0; i < n - 1; i++) {
        int a,b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    ll colors[2] = {0,0};
    vvi u; u.resize(2);
    bool visited[n+5];
    memset(visited, false, sizeof(visited));
    // DFS
    stack<ii> dfs;
    dfs.push(mp(1, 0));
    while (!dfs.empty()) {
        ii head = dfs.top(); dfs.pop();
        int node = head.fi;
        int color = head.se;
        ++colors[color];
        u[color].pb(node);
        visited[node] = true;
        for (int neighbor: adjList[node]) {
            if (!visited[neighbor]) {
                dfs.push(mp(neighbor, (color+1)%2));
            }
        }
    }
    cout << (colors[0]*colors[1] - (n-1)) << '\n';
}
