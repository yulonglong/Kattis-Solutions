// https://open.kattis.com/problems/calculatingdartscores

#include <bits/stdc++.h>
using namespace std;

set<int> validScores;
set<int>::iterator iter;

void initializeValidScores() {
	for (int i = 1; i <= 20; i++) {
		validScores.insert(i);
		validScores.insert(i * 2);
		validScores.insert(i * 3);
	}
}

int memo[4][181];
int p[4][181];

void bottomUpDp() {
	memset(memo,0,sizeof(memo));
	memset(p,-1,sizeof(p));
	for (int i=0;i<=3;i++) {
		memo[i][0] = 1;
	}
	for (int i=1;i<=3;i++) {
		for (int j=1;j<=180;j++) {
			for (iter = validScores.begin(); iter != validScores.end(); iter++) {	
				int prevValue = j - *iter;
				if (prevValue >= 0 && memo[i-1][prevValue] > 0) {
					memo[i][j] += memo[i-1][prevValue];
					p[i][j] = prevValue;
				}
				if (prevValue < 0) break;
			}
			if (memo[i-1][j] > 0) p[i][j] = j;
			memo[i][j] += memo[i-1][j];
		}
	}
}

string getWordAnswer(int score) {
	ostringstream oss;
	if (score % 3 == 0)
		oss << "triple " << score/3;
	else if (score % 2 == 0)
		oss << "double " << score/2;
	else
		oss << "single " << score;
	return oss.str();
}

int main() {
	initializeValidScores();
	bottomUpDp();
	int n; cin >> n;
	vector<int> ans;
	int state = 3;
	if (memo[state][n] == 0) {
		cout << "impossible" << endl;
		return 0;
	}
	while (state >= 0) {
		int prevValue = p[state][n];
		state -= 1;
		if (prevValue == -1) break;
		if (prevValue == n) continue;
		int currAns = n - prevValue;
		ans.push_back(currAns);
		n = prevValue;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << getWordAnswer(ans[i]) << endl;
	}
	return 0;
}
