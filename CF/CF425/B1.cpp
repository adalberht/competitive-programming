#include <bits/stdc++.h>

using namespace std;

bool is_good_string(string s, string pattern, string good_char) {
	if(pattern.length() == 0) return true;
	if(s.length() < pattern.length()) return false;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == pattern[i]) continue;
		else if(pattern[i] == '?') {
			bool is_exist = false;
			for(int j = 0; j < good_char.length(); j++) {
				if(s[i] == good_char[j]) {
					is_exist = true;
					break;
				}
			}
			if(!is_exist) return false;
		}
		else return false;
	}
	return true;
}

bool is_free_string(string free_string, string good_char) {
	for(int i = 0; i < free_string.length(); i++) {
		for(int j = 0; j < good_char.length(); j++) {
			if(good_char[j] == free_string[i]) return false;
		}
	}
	return true;
}

int main() {
	string good_char;
	string pattern;

	cin >> good_char;
	cin >> pattern;

	int bintang = -1;
	for(int i = 0; i < pattern.length(); i++) {
		if(pattern[i] == '*') {
			bintang = i;
		}
	}

	string left_pattern = "";
	string right_pattern = "";

	if(bintang != -1) {
		left_pattern = pattern.substr(0, bintang);
		right_pattern = pattern.substr(bintang+1);
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		bool is_answer = true;
		if(bintang == -1) is_answer = is_good_string(s, pattern, good_char);
		else {
			string left_string;
			int potong_kiri = s.length() < bintang ? s.length() : bintang;
			left_string = s.substr(0, potong_kiri);
			is_answer &= is_good_string(left_string, left_pattern, good_char);

			string right_string;
			int panjang_kanan = right_pattern.length();
			int mulai_kanan = s.length() < panjang_kanan ? s.length() : s.length() - panjang_kanan;
			right_string = s.substr(mulai_kanan);
			is_answer &= is_good_string(right_string, right_pattern, good_char);

			string free_string;
			int mulai = s.length() < bintang ? s.length() : bintang;
			int panjang = s.length() - left_pattern.length() - right_pattern.length();
			free_string = s.substr(mulai, panjang);
			is_answer &= is_free_string(free_string, good_char);

			cout << left_string << endl;
			cout << free_string << endl;
			cout << right_string << endl;
		}
		if(is_answer) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}