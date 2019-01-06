// https://open.kattis.com/problems/downtime

#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

int start[MAX];
int endd[MAX];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> start[i];
		endd[i] = start[i] + 1000;
	}
	stack<int> st;
	int pStart = 0;
	int pEnd = 0;
	int maxLoad = 0;

	while (pStart < n && pEnd < n) {
		if (start[pStart] < endd[pEnd]) {
			st.push(0);
			pStart++;
		} else if (endd[pEnd] <= start[pStart]) {
			st.pop();
			pEnd++;
		}
		maxLoad = max(maxLoad, (int)st.size());
	}
	int totalServer = maxLoad / k;
	if (maxLoad % k > 0) totalServer++;
	cout << totalServer << endl;
	return 0;
}
