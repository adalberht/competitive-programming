#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);\
				cin.tie(0);\
				cout.tie(0)
#define REP(_i, _a) for(int _i = 0; _i < (int)_a; ++_i)
#define FOR(_i, _a, _b) for(int _i = (int)_a; _i <= (int)_b; ++_i)
#define FORD(_i, _a, _b) for(int _i = (int)_a; _i >= (int)_b; --_i)
#define RESET(_a, _value) fill_n(_a,sizeof(_a)/sizeof(_a[0]),_v)
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n';

// DEBUG UTIL
#define DEBUG(args...) { cerr << "> "; \
						 string _s = #args; \
						 replace(_s.begin(), _s.end(), ',', ' '); \
						 stringstream _ss(_s); istream_iterator<string> _it(_ss); \
						 err(_it, args); }

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << ": " << a << " ";
	err(++it, args...);
}

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

struct DoubleHash {
    vector<ll> suf1, suf2, b1, b2;
    ll base1, mod1, base2, mod2;
    
		DoubleHash() {
		}

    DoubleHash(string s, ll _base1 = 97266353LL, ll _mod1 = 972663749LL, ll _base2 = 97336357LL, ll _mod2 = 1000000007LL) {
        base1 = _base1;
        mod1 = _mod1;
        base2 = _base2;
        mod2 = _mod2;
        int n = s.length();
        suf1.assign(n + 1, 0);  // suf[n] = 0
        b1.assign(n + 1, 0);
        b1[0] = 1LL;
        b1[1] = base1;
        for (int i = n - 1; i >= 0; --i) {
            suf1[i] = (s[i] + suf1[i + 1] * b1[1]) % mod1;
        }
        for (int i = 2; i <= n; ++i) {
            b1[i] = (b1[i - 1] * b1[1]) % mod1;
        }

        suf2.assign(n + 1, 0);  // suf[n] = 0
        b2.assign(n + 1, 0);
        b2[0] = 1LL;
        b2[1] = base2;
        for (int i = n - 1; i >= 0; --i) {
            suf2[i] = (s[i] + suf2[i + 1] * b2[1]) % mod2;
        }
        for (int i = 2; i <= n; ++i) {
            b2[i] = (b2[i - 1] * b2[1]) % mod2;
        }
    }

    pair<ll, ll> substr(int l, int r) const { // [l, r]
        ll v1 = suf1[l] - suf1[r + 1] * b1[r - l + 1];
        v1 %= mod1;
        v1 += mod1;
        v1 %= mod1;

        ll v2 = suf2[l] - suf2[r + 1] * b2[r - l + 1];
        v2 %= mod2;
        v2 += mod2;
        v2 %= mod2;

        return {v1, v2};
    }

		pair<ll, ll> substr(ii val) {
			return substr(val.fi, val.se);
		}

};

string s;
DoubleHash hash_value;

map<pll, vii> occurences;
vector<vector<ii>> words;
vector<vector<bool>> after;

set<pll> visited_as_succeed;
set<pll> visited_as_preceed;

vector<ii> parseSentence(string& sentences) {
	int len = sentences.length();
	int last = 0;
	vector<ii> sentenceArr;
	REP(i, len) {
		if (sentences[i] == '.') {
			sentenceArr.pb({last, i-1});
			last = i + 1;
		}
	}
	return sentenceArr;
}

vector<ii> parseWord(ii sentence, int sentence_no) {
	int start = sentence.fi;
	int last = sentence.se;
	int lastPointer = start;
	vector<ii> words;

	int word_no = 0;

	FOR(i, start, last+1) {
		if (i == last+1 || s[i] == ' ' || s[i] == ',') {
			if (i-lastPointer == 0 && s[lastPointer] == ' ') {
				++lastPointer;
				continue;
			}
			words.pb({lastPointer, i-1});
			after[sentence_no].pb(s[i] == ',');
			
			occurences[hash_value.substr(lastPointer, i-1)].pb({sentence_no, word_no++});
			lastPointer = i + 1;
		}
	}

	return words;
}

void dfs(pll val, bool succeed) {
	if (succeed) {
		if (visited_as_succeed.count(val)) return;
		visited_as_succeed.insert(val);
		for (auto occurence: occurences[val]) {
			if (occurence.se + 1 < (int)words[occurence.fi].size()) {
				after[occurence.fi][occurence.se] = true;
				if (!visited_as_preceed.count(hash_value.substr(words[occurence.fi][occurence.se + 1]))) {
					dfs(hash_value.substr(words[occurence.fi][occurence.se + 1]), false);
				}
			}
		}
	}
	
	if (!succeed) {
		if (visited_as_preceed.count(val)) return;
		visited_as_preceed.insert(val);
		for (auto occurence: occurences[val]) {
			if (occurence.se - 1 >= 0) {
				if (!visited_as_succeed.count(hash_value.substr(words[occurence.fi][occurence.se - 1]))) 
					dfs(hash_value.substr(words[occurence.fi][occurence.se - 1]), true);
			}
		}
	}		
}

int main() {
	FAST_IO;
	
	getline(cin, s);
	hash_value = DoubleHash(s);

	vector<ii> sentences = parseSentence(s);
	after.resize(sentences.size());
	
	int i = 0;
	for (auto sentence: sentences) {
		words.pb(parseWord(sentence, i++));
	}

	REP(i1, words.size()) {
		REP(i2, words[i1].size()) {
			if (after[i1][i2] && !visited_as_succeed.count(hash_value.substr(words[i1][i2]))) {
				dfs(hash_value.substr(words[i1][i2]), true);
			}
		}
	}

	string ans = "";

	REP(i1, words.size()) {
		REP(i2, words[i1].size()) {
			FOR(i3, words[i1][i2].fi, words[i1][i2].se) {
				ans += s[i3];
			}
			if (i2 < (int)words[i1].size() - 1)
				ans += (after[i1][i2] ? ", " : " ");
		}
		ans += ". ";
	}	

	cout << ans << endl;

	return 0;
}


