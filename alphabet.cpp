// https://open.kattis.com/problems/alphabet

#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int memo[MAX];

int main() {
	string line; cin >> line;
	int len = line.length();
	memset(memo,0,sizeof(memo));
	memo[0] = 1;
	int globalMaxi = 1;
	for (int i=1;i<len;i++){
		int maxi = 1;
		for (int j=i-1;j>=0;j--) {
			if (line[i] > line[j]) {
				maxi = max(maxi,memo[j]+1);
			}
		}
		memo[i] = maxi;
		globalMaxi = max(globalMaxi, maxi);
	}
	cout << 26 - globalMaxi << endl;
	return 0;
}
