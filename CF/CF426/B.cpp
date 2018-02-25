#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

#define MOD 1000000007
#define NMAX 1e6
#define fi first
#define se second
#define pb push_back
#define mp make_pair

vi primes;

int sieve() {
	bool is_prime[1e5];
	memset(is_prime, true, sizeof(is_prime));
	for(int i = 2; i <= 1e5; i++) {
		if(is_prime[i]) {
			for(int j = i + i; j <= 1e5; j+= i;) {
				is_prime[j] = false;
			}
			primes.pb(i);
		}
	}
}

void factorize(int a, vii b) {
	vector<int>::iterator it = primes.begin();
	while(a > 1 && it != primes.end()) {
		while(a % *it == 0) {
			ii last = b.end();
			if(last.fi != a) {
				b.pb(mp(a, 0));
			} else {
				++last.se;
			}
			a /= *it;
		}
		++it;
	}
} 

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		vii factorA;
		vii factorB;
		factorize(a, factorA);
		for(ii lol: factorA) {
			printf("%d %d\n", lol.fi, lol.se);
		}
	}
	return 0;
}