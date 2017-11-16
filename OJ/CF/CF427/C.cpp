#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int jml[105][105][15];
int grid[105][105][15];

int minX = 105;
int minY = 105;
int maxX = -1;
int maxY = -1;

int query_it(int x1, int y1, int x2, int y2, int k) {
	/* printf("---------------------------------\n");
	printf("%d %d %d %d %d\n", x1, y1, x2, y2, k);
	for (int i = minY; i <= maxY; i++) {
		for(int j = minX; j <= maxX; j++) {
			printf("%d ", jml[j][i][k]);
		} printf("\n");
	}
	printf("---------------------------------\n");*/
	int kanan_bawah = jml[x2][y2][k];
	int kanan_atas = jml[x2][y1-1][k];
	int kiri_bawah = jml[x1-1][y2][k];
	int kiri_atas =  jml[x1-1][y1-1][k]; 
	int ans = kanan_bawah - kanan_atas - kiri_bawah + kiri_atas;
	// printf("%d %d %d %d\n", kanan_bawah, kanan_atas, kiri_bawah, kiri_atas);
	// printf("!!!%d\n", ans);
	return ans;
}

int main() {
	int n, q, c;
	memset(jml, 0, sizeof(jml));
	memset(grid, 0, sizeof(grid));

	scanf("%d %d %d", &n, &q, &c);	
	int x,y,s;
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &s);
		minX = min(x, minX);
		maxX = max(x, maxX);
		minY = min(y, minY);
		maxY = max(y, maxY);
		for(int j = 0; j <= c; j++) {
			grid[y][x][j] += (s + j) % (c+1);
		}
	}
	for(int k = 0; k <= c; k++) {
		for(int i = 1; i < 105; i++) {
			for(int j = 1; j < 105; j++) {
				jml[i][j][k] = jml[i-1][j][k] + jml[i][j-1][k] + grid[i][j][k] - jml[i-1][j-1][k];
			}
		}
	}

	for (int i = 0; i < q; i++) {
		int x1, x2, y1, y2, t;
		scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
		printf("%d\n", query_it(y1, x1, y2 ,x2, t % (c+1)));
	}
	return 0;
}