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
const int MAX = 2e5+5;

int N;
int arr[MAX];
int last[MAX];

int main() {
  FAST_IO;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    last[arr[i]] = i;
  }
  int minimum = last[arr[0]];
  for (int i = 0; i < N; ++i) {
    minimum = min(minimum, last[arr[i]]);
  }
	cout << arr[minimum] << '\n';
	return 0;
}
