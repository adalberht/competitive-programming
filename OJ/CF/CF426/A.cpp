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

int main() {
	char start ,end;
	int n;
	
	scanf("%c %c", &start, &end);
	scanf("%d", &n);
	if (n > 4) n %= 4;
	char cw[4] = {'<', '^', '>', 'v'};
	char ccw[4] = {'<', 'v', '>', '^'};
	int pos_cw, pos_ccw;
	for(int i = 0; i < 4; i++) {
		if(cw[i] == start) pos_cw = i;
		if(ccw[i] == start) pos_ccw = i;
	}
	bool is_cw = cw[(pos_cw+n)%4] == end;
	bool is_ccw = ccw[(pos_ccw+n)%4] == end; 
	if(is_cw && !is_ccw) printf("cw\n");
	else if(is_ccw && !is_cw) printf("ccw\n");
	else printf("undefined\n");
	return 0;
}