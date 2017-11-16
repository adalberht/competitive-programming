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
#define __SUBMIT__  ios_base::sync_with_stdio(false); \
          cin.tie(0); \
          cout.tie(0);
#define EPS 1e-8

bool used[105];
int arr[105];
int n,x ;
set<int> s;

int find_mex() {
  for(int i = 0; i < n; i++) {
    if (!used[i]) return i;
  }
  return -1;
}


int main() {
  scanf("%d %d", &n, &x);
  int baca;
  int minimal = 105;
  for(int i = 0; i < n; i++){
    s.insert(scanf("%d", &baca));
    used[baca] = true;
    minimal = min(minimal, baca);
  }
  int operation = 0;
  if(used[x]) ++operation;
  for(int i = 0; i < x; i++) {
    if (!used[i]) {
      used[i] = true;
      ++operation;
    }
  } 
  printf("%d\n", operation);
  return 0;
}
