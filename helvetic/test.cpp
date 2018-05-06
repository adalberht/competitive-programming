#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

vector<pair<int, int>> arr;

int main() {
	int n;

	cin >> n;
	arr.assign(n, {1, 1});

	arr[n-1].fi = 1000;

	for (auto elem: arr) {
		cout << elem.fi << " " << elem.se << endl;
	}


	return 0;
}