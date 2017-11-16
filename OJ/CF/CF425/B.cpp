#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define pb push_back

int main() {
	string good_char;

	cin >> good_char;
	
	string p;

	cin >> p;

	int left = p.length()-1;
	int right = p.length()+1;
	bool is_pattern = true;
	for(int j = 0; j < p.length(); j++) {
		if(p[j] == '*') {
			left = j;
			right = j + 1;
		}
	}

	int n;

	cin >> n;
	getchar();
	for(int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		string pattern_left;
		if(left <= s.length()) {
			pattern_left = s.substr(0, left);
		} else {
			pattern_left = s;
		}
		cout << pattern_left << endl;
		
		bool is_pattern = true;
		if(pattern_left.length() < left+1) {
			is_pattern = false;
		}
		for(int j = 0; j < pattern_left.length(); j++) {
			if(!is_pattern) break;
			if(pattern_left[j] == p[j]) continue;
			else if(p[j] == '?') {
				bool is_good = false;
				for(int k = 0; k < good_char.length(); k++) {
					if(good_char[k] == pattern_left[j]) {
						is_good = true;
						break;
					}
				}
				if(!is_good) {
					is_pattern = false;
					break;
				}
			} else {
				is_pattern = false;
			}
		}
		if(left != p.length()-1 && right != p.length() + 1 && is_pattern) {
			int right_index = s.length() - (p.length() - right);
			int right_size = right_index - left - 1;
			string pattern_free, pattern_right;
			if(right < s.length()) {
				pattern_free = s.substr(left+1, right_size);
				pattern_right = s.substr(right_index);
			} else {
				pattern_free = "";
				pattern_right = "";
			}
			cout << pattern_free << endl;
			cout << pattern_right << endl;
			for(int j = 0; j < pattern_free.length(); j++) {
				for(int k = 0; k < good_char.length(); k++) {	
					if(pattern_free[j] == good_char[k]) {
						is_pattern = false;
						break;
					}
				}
				if(!is_pattern) break;
			}

			if(pattern_right.length() < p.length() -right) is_pattern = false;
			for(int j = 0; j < pattern_right.length(); j++) {
				if(!is_pattern) break;
				if(pattern_right[j] == p[j+right]) continue;
				if(p[j+right] == '?') {
					bool is_good = false;
					for(int k = 0; k < good_char.length(); k++) {
						if(good_char[k] == pattern_right[j]) {
							is_good = true;
							break;
						}
					}
					if(!is_good) {
						is_pattern = false;
						break;
					}
				} else {
					is_pattern = false;
					break;
				}
			}
		}
		if(is_pattern) printf("YES\n");
		else printf("NO\n");
	}
}