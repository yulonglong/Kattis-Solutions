// https://open.kattis.com/problems/recount

#include<bits/stdc++.h>
using namespace std;

map<string,int> dict;
map<string,int>::iterator iter;

int main() {
	string line;
	int index = 0;
	while (getline(cin, line)) {
		if (line == "***") break;
		iter = dict.find(line);
		if (iter == dict.end()) {
			// Means not found
			dict.insert(pair<string,int>(line,1));
		}
		else {
			iter->second += 1;
		}		
	}
	int currMax = 0;
	string winnerName = "";
	int currCount = 0;
	for (iter = dict.begin(); iter != dict.end(); iter++) {
		if (currMax < iter->second) {
			currMax = iter->second;
			winnerName = iter->first;
			currCount = 1;
		}
		else if (currMax == iter->second) {
			currCount += 1;
		}
	}
	if (currCount != 1) {
		cout << "Runoff!" << endl;
	}
	else {
		cout << winnerName << endl;
	}
	return 0;
}

