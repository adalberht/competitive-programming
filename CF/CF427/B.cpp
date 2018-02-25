#include <bits/stdc++.h>

using namespace std;

int sum_digits(string n) {
	int temp = 0;
	for(int i = 0; i < n.length(); i++) {
		temp += (int)n[i] - (int)'0';
	}
	return temp;
}

int cnt_zero(string n) {
	int cnt = 0;
	for(int i = 0; i < n.length(); i++) {
		++cnt;
	}
	return cnt;
}

int main() {
	int k;
	string n;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	cin >> n;
	sort(n.begin(), n.end());
	int ans = 0;
	int sum_of_digits = sum_digits(n);
	if (sum_of_digits >= k) {
		printf("0\n");
	} else {
		// cout << sum_of_digits << endl;
		int selisih = k - sum_of_digits;
		int cnt = 0;
		int i = 0;
		while(selisih > 0) {
			selisih -= 9 - ((int)n[i] - (int)'0');
			++cnt;
			++i;
		}
		printf("%d\n", cnt); 
	}
	return 0;
}

