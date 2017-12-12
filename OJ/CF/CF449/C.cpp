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
const int MAX_N = 1e5;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

string a = "What are you doing while sending ";

string b = "? Are you busy? Will you send ";

string c = "?";

ll panjang[MAX_N+5];

char query(int n, ll k) {
  cout << "!!!" << n << " " << k << endl;
  if (k > panjang[n]) return '.';
  if (n == 0) return f0[k];

  if (k < a.length()) {
    cout << "masuk a" << endl;
    return a[(int)k];
  }

  if (k == a.length() + 1 || k == a.length() + panjang[n-1] + 2) {
    cout << "petik gak jelas" << endl;
    return '\"';
  }

  if (k < a.length() + 1 + panjang[n-1] + 1) {
    cout << "masuk f(n-1)" << endl;
    return query(n-1, k-a.length()-1);
  }

  if (k < a.length() + 1 + panjang[n-1] + 1 + b.length()) {
    cout << "masuk b" << endl;
    return b[k - (a.length() + 1 + panjang[n-1] + 1)];
  }

  if (k == a.length() + 1 + panjang[n-1] + 1 + b.length() + 1 || k == a.length() + 1 + panjang[n-1] + 1 + b.length() + 1 + panjang[n-1] + 1) {
    cout << "masuk petik gak jelas 2" << endl;
    return '\"';
  }

  if (k < a.length() + 1 + panjang[n-1] + 1 + b.length() + panjang[n-1] + 2) {
    cout <<"masuk f(n-1) 2" << endl;
    return query(n-1, k-a.length()-panjang[n-1]-2-b.length()-1);
  }
  cout <<"tanda tanya terakhir" << endl;
  return c[0];
}

int main() {

  panjang[0] = f0.length();
  for (int i = 1; i <= MAX_N; ++i) {
    panjang[i] = a.length() + 1 + panjang[i-1] + 1 + b.length() + 1 + panjang[i-1] + 1 + c.length();
    if (panjang[i] >= 1e18) cout << i << endl;
  }

  int q;
  cin >> q;
  string ans = "";
  while (q--) {
    ll n, k;
    cin >> n >> k;
    --k;
    char temp = query(n, k);
    cerr << "!: " << temp << endl;
    ans += query(n, k);
  }

  printf("Panjang print maks: %lld\n", panjang[MAX_N]);
  cout << ans << endl;

	return 0;
}
