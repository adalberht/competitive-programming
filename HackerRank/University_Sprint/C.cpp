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
int x, y;
int matriks[65][65];
bool visited[65][65];
char direction;
map<char, string> priority;
map<char, int> move_row;
map<char, int> move_col;

bool valid_to_visit(int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < n && !visited[row][col]);
}

void dfs(int row, int col, int cur) {
    visited[row][col] = true;
    matriks[row][col] = cur;
    for(int i = 0; i < 4; ++i) {
        char move = priority[direction][i];
        int new_row = row + move_row[move];
        int new_col = col + move_col[move];
        if (valid_to_visit(new_row, new_col)) {
            dfs(new_row, new_col, cur+1);
            break;
        }
    }
}

int main() {
    FAST_IO;

    cin >> n;
    cin >> direction;
    cin >> x >> y;
    
    priority['e'] = "esnw";
    priority['w'] = "wnse";
    priority['s'] = "sewn";
    priority['n'] = "nwes";
    move_row['e'] = move_row['w'] = 0;

    move_col['e'] = 1;
    move_col['w'] = -1;
    move_col['n'] = move_col['s'] = 0;
    move_row['n'] = -1;
    move_row['s'] = 1;

    dfs(x, y, 1);
    for (int i = 0; i < n; ++i) {
        cout << matriks[i][0];
        for (int j = 1; j < n; ++j) {
            cout << " " << matriks[i][j];
        }
        cout << '\n';
    }
	return 0;
}
