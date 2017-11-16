#include <bits/stdc++.h>

using namespace std;

vector< vector<char> > grid;

int main() {
    grid.resize(15);
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            grid[i].pb(c);
        }
    }

    int minimum = try_to_start_from(0,0);
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            minimum = min(minimum, try_to_start_from(i,j));
        }
    }

    cout << minimum << '\n';
    return 0;
}