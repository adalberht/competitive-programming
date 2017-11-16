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

int A;

int main() {
    cin >> A;
    if (A == 1) {
        cout << "1 1\n1\n";
    } else {
        cout << 2*(A-1) << " " << 2 << "\n";
        cout << 1 << " " << 2 << "\n";
    }
    return 0;
}
