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
#define FAST_IO  ios_base::sync_with_stdio(false); \
					cin.tie(0); \
					cout.tie(0);
#define EPS 1e-8

int main() {
    int n;

    cin >> n;
    string nama;
    map<string, bool> ada;
    for(int i = 0; i < n; i++) {
        cin >> nama;
        if (ada.count(nama)) {
            cout << "YES\n";
        } else {
            ada[nama] = true;
            cout << "NO\n";
        }
    }
	return 0;
}
