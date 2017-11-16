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

int n;
int arr[305][305];

struct point {
    int row;
    int col;
    int val;
};

void bfs(int x, int y, int val) {
    bool is_visited[n+5][n+5];
    memset(is_visited, false, sizeof(is_visited));
    
    queue<point> q;
    point p;
    p.row = x;
    p.col = y;
    p.val = val;
    q.push(p);
    while(!q.empty()) {
        point front = q.front(); q.pop();
        int i = front.row;
        int j = front.col;
        int cur = front.val;
        if (i >= 0 && i < n && j >= 0 && j < n && !is_visited[i][j]) {
            is_visited[i][j] = true;
            arr[i][j] += cur;
            --cur;
            if (cur >= 0) {
                point p2; p2.val = cur;
                p2.row = i; p2.col = j-1; q.push(p2);
                p2.col = j+1; q.push(p2);
                p2.row = i-1; p2.col = j; q.push(p2);
                p2.row = i+1; q.push(p2);
                p2.row = i-1; p2.col = j-1; q.push(p2);
                p2.col = j+1; q.push(p2);
                p2.row = i+1; p2.col = j-1; q.push(p2);
                p2.col = j+1; q.push(p2);
            }
        }
    }
}

int main() {
    FAST_IO;
    int m;
    cin >> n;
    cin >> m;

    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        bfs(x, y, w);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // printf("%d ", arr[i][j]);
            ans = max(ans, arr[i][j]);
        } // printf("\n");
    }
    cout << ans << '\n';
    return 0;
}
