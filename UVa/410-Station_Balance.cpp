#include <bits/stdc++.h>

using namespace std;

int main() {
  int S, C;
  int tc = 1;
  while(scanf("%d %d", &C, &S) != EOF) {
    double avg = 0;
    int arr[2*C + 5];
    for (int i = 0; i < S; ++i) {
      scanf("%d", &arr[i]);
      avg += arr[i];
    }
    for(int i = S; i < 2*C; i++) {
      arr[i] = 0;
    }
    avg /= (double)C;
    sort(arr, arr + 2*C);
    
    double imbalance = 0;
    printf("Set #%d\n", tc);
    for(int i = 0; i < C; i++) {
      printf(" %d:", i);
      if (arr[i] != 0) printf(" %d", arr[i]);
      if (arr[2*C-i-1] != 0) printf(" %d", arr[2*C-i-1]);
      imbalance += fabs((double)(arr[i] + arr[2*C-i-1]) - avg);
      printf("\n");
    }
    printf("IMBALANCE = %.5lf\n\n", imbalance);
    ++tc;
  }
  return 0;
}
