#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

#define MOD 1000000007
#define NMAX 100000
#define fi first
#define se second
#define pb push_back
#define mp make_pair

vi primes;

int sieve() {
	bool is_prime[NMAX];
	memset(is_prime, true, sizeof(is_prime));
	for(int i = 2; i <= NMAX; i++) {
		if(is_prime[i]) {
			for(int j = i + i; j <= NMAX; j+= i) {
				is_prime[j] = false;
			}
			primes.pb(i);
		}
	}
}

void factorize(int a, vii& b) {
	vector<int>::iterator it = primes.begin();
	// cout << "Factor" << endl;
	while(a > 1 && it != primes.end()) {
		while(a % *it == 0) {
			cout << *it << endl;
			if (b.empty()) {
				b.pb(mp(*it,1));
			} else {
				ii last = b.back();
				// cout << last.fi << " " << last.se << endl;
				if(last.fi != *it) {
					b.pb(mp(*it, 1));
				} else {
					b[b.size()-1] = mp(*it, last.se+1);
				}
			}
			a /= *it;
		}
		++it;
	}
} 

int main() {
	int n;
	sieve();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		vii factorA;
		vii factorB;
		factorize(a, factorA);
		factorize(b, factorB);
		printf("Factor A:\n");
		for(ii lol: factorA) {
			printf("	%d^%d\n", lol.fi, lol.se);
		}
		printf("Factor B:\n");
		for(ii lol: factorB) {
			printf(" 	%d^%d\n", lol.fi,lol.se);
		}
		if (factorA.size() != factorB.size()) {
			printf("No\n");
			continue;
		}
		bool ans = true;
		for(int j = 0; j < factorA.size(); j++) {
			ii A = factorA[j];
			ii B = factorB[j];
			if(A.fi != B.fi) {
				ans = false;
				break;
			}
			if(abs(A.se - B.se) != 1) {
				ans = false;
				break;
			}
		}
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}