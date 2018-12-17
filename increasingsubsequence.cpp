// https://open.kattis.com/problems/increasingsubsequence

#include <bits/stdc++.h>
using namespace std;
#define MAX 202

int num[MAX];
int memo[MAX];
int p[MAX];

int main() {
	string line;
	while (getline(cin, line) && line != "0") {
		memset(num, 0, sizeof(num));
		memset(memo, 0, sizeof(memo));
		memset(p, -1, sizeof(p));
		istringstream istream(line);
		int idx = 0;
		int temp;
		istream >> temp;  // throw away starting number
		while (istream >> temp) {
			num[idx++] = temp;
		}
		memo[0] = 1;
		int globalMaxi = 1;
		int globalMaxiIdx = 0;
		for (int i = 1; i < idx; i++) {
			int maxi = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (num[i] > num[j]) {
					if (maxi < memo[j] + 1) {
						maxi = memo[j] + 1;
						p[i] = j;
					} else if (maxi == memo[j] + 1) {
						if (num[j] < num[p[i]])
							p[i] = j;
					}
				}
			}
			memo[i] = maxi;
			if (globalMaxi < maxi) {
				globalMaxi = maxi;
				globalMaxiIdx = i;
			} else if (globalMaxi == maxi) {
				if (num[i] < num[globalMaxiIdx])
					globalMaxiIdx = i;
			}
		}

		stack<int> ans;
		while (globalMaxiIdx != -1) {
			ans.push(num[globalMaxiIdx]);
			globalMaxiIdx = p[globalMaxiIdx];
		}
		cout << ans.size();  // Same as globalMaxi
		while (!ans.empty()) {
			cout << " " << ans.top();
			ans.pop();
		}
		cout << endl;
	}
	return 0;
}
