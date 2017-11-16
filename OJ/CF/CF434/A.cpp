#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod_exp(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  ll ret = mod_exp(a, b/2);
  ret *= ret;
  if (b % 2 == 1) ret *= a;
  return ret;
}

int main() {
  ll n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << '\n';
    return 0;
  }
  for(int a = 0; a <= 10; a++) {
    for(int b = 0; b <= 10; b++) {
      ll dua = mod_exp(2, b);
      ll lima = mod_exp(5, a);
      if (n * dua * lima % mod_exp(10,k) == 0) {
        cout << n * dua * lima << '\n';
        return 0;
      }
    }
  }
  return 0;
}
