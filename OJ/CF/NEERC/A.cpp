#include <bits/stdc++.h>

using namespace std;

int n;
int l[100+5];
int r[100+5];

int par[105];

int get_most_left(int i) {
  if (l[i] == 0) {
    return i;
  }
  par[i] = get_most_left(l[i]);
  return par[i];
}

bool one_linked_list() {
  set<int> parents;
  memset(par, -1, sizeof(par));
  for(int i = 1; i <= n; i++) {
    if (par[i] == -1) {
      parents.insert(get_most_left(i));
    }
  }
  // cout << parents.size() << endl;
  if (parents.size() == 1) return true;
  return false;
}

int main() {

  memset(par, -1, sizeof(par));
  scanf("%d", &n);

  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
  }

  // Find node which doens't have prev
  while(!one_linked_list()) {
    for(int i = 1; i <= n; i++) {
      if (r[i] == 0) {
        for(int j = 1; j <= n; j++) {
          if (i != j && l[j] == 0 && get_most_left(i) != get_most_left(j) && (r[i] != l[j] || (r[i] == 0  && l[j]== 0))) {
            r[i] = j;
            l[j] = i;
            break;
          }
        }
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    printf("%d %d\n",l[i],r[i]);
  }
  return 0;
}