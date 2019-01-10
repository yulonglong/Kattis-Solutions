// https://open.kattis.com/problems/aprizenoonecanwin

#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
int main() {
	long long n, x;
	cin >> n >> x;
	long long items[MAX];
	for (int i = 0; i < n; i++) cin >> items[i];
	sort(items, items + n);

	int answer = 1;
	for (int i = n - 1; i >= 1; i--) {
		int curr = items[i];
		int diff = x - items[i];
		if (diff <= 0) continue;
		
		// Find elements strictly greater than diff to make sum of pair > x
		int idx = upper_bound(items, items + i - 1, diff) - items;
		// If the value of diff is bigger than all of the elements, it will return the last index
		// so check whether that's the case
		if ((idx == i-1) && (items[idx] <= diff)){
			answer = i + 1;
			break;
		}
	}
	cout << answer << endl;

	return 0;
}
