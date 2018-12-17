// https://open.kattis.com/problems/awkwardparty

#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
typedef pair<int, int> ii;

map<int, int> dict;
map<int, int>::iterator iter;
int main() {
	int n; cin >> n;
	dict.clear();
	int currMin = INF;
	for (int i = 0; i < n; i++) {
		int curr; cin >> curr;
		iter = dict.find(curr);
		if (iter != dict.end()) {
			int diff = i - (iter->second);
			iter->second = i;
			currMin = min(currMin, diff);
		}
		else {
			dict.insert(ii(curr, i));
		}
	}
	if (currMin == INF) currMin = n;
	cout << currMin << endl;
	return 0;
}
