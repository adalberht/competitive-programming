#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;
    bool exist_non_zero = false;
    string remove_trailing_zero = "";
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] != '0') {
            exist_non_zero = true;
            remove_trailing_zero += s[i];
        } else if (exist_non_zero) {
            remove_trailing_zero += s[i];
        }
    }
    int last = remove_trailing_zero.size()-1;
    bool is_palindrome = true;
    for(int i = 0; i < remove_trailing_zero.length() / 2; i++) {
        if (s[i] != s[last]) {
            is_palindrome = false;
            break;
        }
        --last;
    }
    if (is_palindrome) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}