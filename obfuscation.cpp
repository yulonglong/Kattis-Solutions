// https://open.kattis.com/problems/obfuscation

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define CHARMAX 26
typedef pair<string,int> si;

class TheWord {
	public:
		string word;
		char first;
		char last;
		int len;
		int freq[CHARMAX];
	TheWord(const string& word) {
		this->word = word;
		this->len = word.length();
		this->first = word[0];
		this->last = word[word.length() - 1];
		memset(freq,0,sizeof(freq));
		for(int i=1;i<word.length()-1;i++) {
			freq[word[i] - 'a']++;
		}
	}
	TheWord(int freqs[CHARMAX], char first, char last, int wordLen) {
		this->word = "";
		this->first = first;
		this->last = last;
		this->len = wordLen;
		memset(freq,0,sizeof(freq));
		for(int i=0;i<CHARMAX;i++) {
			this->freq[i] = freqs[i];
		}
	}
	bool operator == (const TheWord& rhs) {
		if (this->first != rhs.first) return false;
		if (this->last != rhs.last) return false;
		for(int i=0;i<CHARMAX;i++) {
			if (freq[i] != rhs.freq[i]) return false;
			return true;
		}
	}
	string getKey() {
		ostringstream oss;
		oss << first << last << len;
		for (int i=0;i<CHARMAX;i++) oss << freq[i];
		string key = oss.str();
		return key;
	}
};


map<string, int> dict;
map<string, int>::iterator iter;
set<string> ambiguousSet;
vector<TheWord> words;
string longStr;
int longStrLen;
bool ambiguous = false;

int start[MAX];
int end[MAX];
int memo[MAX][MAX];
int dp[MAX];
int p[MAX];


void findSolution(int start) {
	for (int j = start; j < longStrLen; j++) {
		if (memo[start][j] != -1) {
			dp[j+1] += 1;
			p[j+1] = start;
			findSolution(j+1);
		}
	}
}

int main() {
	cin >> longStr;
	longStrLen = longStr.length();
	// cout << "Len " << longStrLen << endl;
	int n;
	cin >> n;
	dict.clear();
	words.clear();
	ambiguousSet.clear();

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		TheWord theWord(word);
		words.push_back(theWord);
		string key = theWord.getKey();

		if (dict.find(key) != dict.end()) {
			ambiguousSet.insert(key);
		}
		else {
			dict.insert(si(key, i));
		}
	}

	memset(memo, -1, sizeof(memo));
	int freq[CHARMAX];
	memset(freq, 0, sizeof(freq));
	for (int i = 0; i < longStrLen; i++) {
		memset(freq, 0, sizeof(freq));
		for (int j = i; j < longStrLen; j++) {
			TheWord theWord(freq, longStr[i], longStr[j], (j-i+1));
			string key = theWord.getKey();
			iter = dict.find(key);
			// cout << key << endl;
			if (iter != dict.end()) {
				// cout << "Found " << key <<  " :: " << i << " -> " << j << endl;
				memo[i][j] = iter->second;
			}
			if (i < j) freq[longStr[j] - 'a']++;
		}
	}

	memset(dp,0,sizeof(dp));
	memset(p,-1,sizeof(p));
	findSolution(0);
	if (dp[longStrLen] == 0) cout << "impossible" << endl;
	else if (dp[longStrLen] > 1) cout << "ambiguous" << endl;
	else if (dp[longStrLen] == 1) {
		vector<TheWord> ans;
		int parent = p[longStrLen];
		int curr = longStrLen;
		while (true) {
			TheWord currWord = words[memo[parent][curr-1]];
			ans.push_back(currWord);
			
			// Check whether using word from ambiguous set
			string key = currWord.getKey();
			if (ambiguousSet.find(key) != ambiguousSet.end()) {
				ambiguous = true;
				break;
			}

			if (parent == 0) break;
			curr = parent;
			parent = p[parent];
		}
		
		if (ambiguous) {
			cout << "ambiguous" << endl;
		}
		else {
			cout << ans[ans.size()-1].word;
			for (int i=ans.size()-2;i>=0;i--) {
				cout << " " << ans[i].word;
			}
			cout << endl;
		}
	}

	return 0;
}
