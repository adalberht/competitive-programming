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
    string inp;
    cin >> inp;
    if(inp[1] == '+') {
        cout << (int)inp[0]-(int)'0' + (int)inp[2]-(int)'0' << '\n';
    } else {
        cout << (int)inp[0]-(int)'0' - (int)inp[2]+(int)'0' << '\n';
    }
	return 0;
}
