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
#define FAST_IO  ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;


vector<int> arr;
int N;

int main() {
  FAST_IO;

  cin >> N;
  arr.resize(N+5);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  int count = 0;
  for (int i = 1; i < N - 1; ++i) {
    if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) ++count;
    else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) ++count;
  }

  cout << count << '\n';

  return 0;
}
