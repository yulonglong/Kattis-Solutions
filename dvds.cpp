// https://open.kattis.com/problems/dvds

#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int curr = 0;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			if (curr + 1 == temp) curr++;
		}
		cout << n - curr << endl;
	}
	return 0;
}
