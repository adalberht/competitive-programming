#include <bits/stdc++.h>
#define sz(a) (int) a.size()

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int INF = 1e9 + 1000;
const int MAX = 10;

struct point {
	int x, y;
};

int R, B;
point a[MAX+5], b[MAX+5];
int order[MAX+5];

int orientation(point p, point q, point r) {
	int val = (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x);

	if (val == 0) return 0;
	return val > 0 ? 1 : 2;
}

bool onSegment(point a, point q, point b) {
	if (min(a.x, b.x) <= q.x && q.x <= max(a.x, b.x) && 
		min(a.y, b.y) <= q.y && q.y <= max(a.y, b.y))
		return true;

	return false;
}

bool intersect(point a, point b, point c, point d) {
	int o1 = orientation(a, b, c);
	int o2 = orientation(a, b, d);
	int o3 = orientation(c, d, a);
	int o4 = orientation(c, d, b);

	if (o1 != o2 && o3 != o4) return true;

	if (o1 == 0 && onSegment(a, c, b)) return true;
	if (o2 == 0 && onSegment(a, d, b)) return true;
	if (o3 == 0 && onSegment(c, a, d)) return true;
	if (o4 == 0 && onSegment(c, b, d)) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> B;
	for (int i=0; i<R; i++) cin >> a[i].x >> a[i].y;
	for (int i=0; i<B; i++) cin >> b[i].x >> b[i].y;

	if (R != B) {
		cout << "No\n";
		return 0;
	}

	for (int i=0; i<R; i++) order[i] = i;

	do {
		bool flag = true;

		for (int i=0; i<R; i++) // rebel
			for (int j=i+1; j<R; j++) { // base
				if (intersect(a[order[i]], b[i], a[order[j]], b[j])) {
					flag = false;
					break;
				}
			}

		if (flag) {
			// for (int i=0; i<R; i++) cout << order[i] << " "; cout << "\n";
			cout << "Yes\n";
			return 0;
		}

	} while (next_permutation(order, order + R));

	cout << "No\n";
	return 0;
}