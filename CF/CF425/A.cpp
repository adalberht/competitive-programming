#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define pb push_back

int main() {
	long long a,b;

	scanf("%lld %lld", &a, &b);
	if((a / b) % 2 == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}