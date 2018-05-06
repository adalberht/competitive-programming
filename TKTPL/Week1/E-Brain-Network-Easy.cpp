#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define mp make_pair
#define pb push_back

const int MAX_N = 1e3 + 5;

int n, m;
vector<ii> edge_list;

int main() {

    cin >> n >> m;

    vvi adj_list1;
    adj_list1.resize(n+5);
    int v1, v2;


    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        edge_list.push_back(make_pair(v1, v2));
        adj_list1[v1].push_back(v2);
        adj_list1[v2].push_back(v1);
    }
    bool answer = true;
    queue<int> q;
    q.push(1);
    bool visited[n+5];
    memset(visited, false, sizeof(visited));

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        visited[cur] = true;
        for (int adj: adj_list1[cur]) {
            if (!visited[adj]) {
                q.push(adj);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            answer = false;
            break;
        }
    }
    for (int i = 0; i < m; ++i) {
        vvi adj_list;
        adj_list.resize(n+5);
        for (int j = 0; j < m; ++j) {
            if (j == i) continue;
            int u = edge_list[j].first;
            int v = edge_list[j].second;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        queue<int> q2;
        q2.push(1);
        bool visited2[n+5];
        memset(visited2, false, sizeof(visited2));
        while (!q2.empty()) {
            int cur = q2.front(); q2.pop();
            visited2[cur] = true;
            for (int adj: adj_list[cur]) {
                if (!visited2[adj]) {
                    q2.push(adj);
                }
            }
        }
        bool visited_all = true;
        for (int i = 1; i <= n; ++i) {
            if (!visited2[i]) {
                visited_all = false;
                break;
            }
        }
        if (visited_all) {
            answer = false;
            break;
        }
    }

    if (answer) cout << "yes\n";
    else cout << "no\n";

    return 0;
}