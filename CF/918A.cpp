#include <bits/stdc++.h>

using namespace std;

int fib[50];

void init() {
    fib[0] = fib[1]= fib[2] = 1;
    for (int i = 3; i <= 20; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }    
}

bool isFibonacci(int n) {
    for (int i = 0; i <= 20; ++i) {
        if (fib[i] == n) return true;
    }
    return false;
}

int main() {
    init();
    int n;

    cin >> n;
    string ans = "";
    for (int i = 1; i <= n; ++i) {
        if (isFibonacci(i)) ans += "O";
        else ans += "o";
    }
    cout << ans << endl;
}
