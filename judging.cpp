// https://open.kattis.com/problems/judging

#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
typedef pair<string, int> si;

map<string, int> dict;
map<string, int>::iterator iter;
int freq1[MAX];
int freq2[MAX];

int main() {
	dict.clear();
	memset(freq1, 0, sizeof(freq1));
	memset(freq2, 0, sizeof(freq2));
	string line;
	getline(cin, line);
	int n = atoi(line.c_str());
	int idx = 0;
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		iter = dict.find(line);
		if (iter != dict.end()) {
			freq1[iter->second] += 1;
		}
		else {
			dict.insert(si(line, idx));
			freq1[idx] += 1;
			idx++;
		}
	}
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		iter = dict.find(line);
		if (iter != dict.end()) {
			freq2[iter->second] += 1;
		}
		else {
			dict.insert(si(line, idx));
			freq2[idx] += 1;
			idx++;
		}
	}
	int count = 0;
	for (int i = 0; i < idx; i++) {
		// cout << freq1[i] << " : " << freq2[i] << endl;
		count += min(freq1[i], freq2[i]);
	}
	cout << count << endl;
	return 0;
}
