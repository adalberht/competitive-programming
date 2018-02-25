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

const int MAX_N = 1e7;

int n;

int arr[MAX_N];

int if_removed_will_increase[MAX_N];

int max1[MAX_N];
int max2[MAX_N];

int min1 = MAX_N;

int is_record_initially[MAX_N];

int main() {
  FAST_IO;

  cin >> n;

  int initial_records = 0;


  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; ++i) {
    min1 = min(min1, arr[i]);

  }

  set<int, greater<int> > s;
  s.insert(0);
  for (int i = 0; i < n; ++i) {
    s.insert(arr[i]);
    max1[i] = *(s.begin());
    max2[i] = *(++s.begin());
    if (arr[i] >= max1[i]) {
      is_record_initially[i] = true;
      ++initial_records;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (arr[i] < max1[i] && arr[i] >= max2[i]) {
      ++if_removed_will_increase[max1[i]];
    }
  }

  int max_records = -1;
  int ans = max1[n-1];
  for (int i = 0; i < n; ++i) {
    int if_removed = initial_records - is_record_initially[i] + if_removed_will_increase[arr[i]];
    if (if_removed > max_records) {
      max_records = if_removed;
      ans = arr[i];
    } else if (if_removed == max_records) {
      ans = min(ans, arr[i]);
    }
  }

  cout << ans << '\n';

	return 0;
}
