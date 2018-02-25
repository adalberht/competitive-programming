#include <bits/stdc++.h>

using namespace std;

int main() {
	int s, v1, v2, t1, t2;

	cin >> s >> v1 >> v2 >> t1 >> t2;
	int c1 = s * v1 + 2 * t1;
	int c2 = s * v2 + 2 * t2;

	if(c1 < c2) printf("First\n");
	else if(c2 < c1) printf("Second\n");
	else printf("Friendship\n");
	return 0;
}