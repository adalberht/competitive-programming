#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,m;
  scanf("%d %d", &n, &m);
  int floor[105];
  int maks = 0;
  for(int i = 0; i < 105; i++) floor[i] = -1;
  for(int i = 0; i < m; i++) {
    int ki, fi;
    scanf("%d %d", &ki, &fi);
    floor[ki] = fi;
    maks = max(maks, ki);
  }

  vector<int> solutions;
  for(int range = 1; range <= 100; range++) {
    bool is_solution = true;
    for(int i = 1; i <= maks; i++) {
      int fi = floor[i];
      if (fi != -1) { 
        // cout << range << " " << i << " " << fi << " " << (int)ceil(i/(double)range) << endl;
        if ((int)ceil(i/(double)range) == fi) continue;
        is_solution = false;
        break; 
      }
    }
    if (is_solution) solutions.push_back(range);
  }
  if (solutions.size() < 1) {
    printf("-1\n");
  }
  else {
    int solution = (int)ceil(n/(double)solutions[0]);
    for(int i = 1; i < solutions.size(); i++) {
      if ((int)ceil(n/(double)solutions[i]) != solution) {
        printf("-1\n");
        return 0;
      }
    }
    printf("%d\n", solution);
  }
  return 0;
}