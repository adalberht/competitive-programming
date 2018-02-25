#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

int main() {
  int n;
  FAST_IO;
  cin >> n;
  int arr[n+5];
  for (int i = 0; i < n; ++i) { cin >> arr[i]; }
  int player1 = 1;
  int player2 = 2;
  int spectator = 3;
  for (int i = 0; i < n; ++i) {
    if (arr[i] != player1 && arr[i] != player2) {
      cout << "NO" << endl;
      return 0;
    }
    int temp;
    if (player1 != arr[i]) {
      temp = player1;
      player1 = player2;
      player2 = temp;
    }

    temp = player2;
    player2 = spectator;
    spectator = temp;
  }
  cout << "YES" << endl;
  return 0;
}
