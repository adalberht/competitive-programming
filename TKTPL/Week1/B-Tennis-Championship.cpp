#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull f[10000];
ull n;

int main() {
	
	f[0] = 1LL;
	f[1] = 2LL;
	for (int i = 2; i <= 100000; ++i) {
		f[i] = f[i-1] + f[i-2];
		if (f[i] > 1e18) break;
	} 
	
	cin >> n;
	for (int i = 1; i <= 100000; ++i) {
			if (n < f[i]) {
				cout << i - 1 << endl;
				break;
			}
	}
	
}