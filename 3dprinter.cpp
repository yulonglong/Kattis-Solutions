// https://open.kattis.com/problems/3dprinter

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = 3;
	if (n == 1) ans = 1;
	else if (n == 2) ans = 2;
	else {
		int prev = 2;
		int curr = 4;
		while (prev <= 10000) {
			if (prev < n && n <= curr) {
				break;
			}
			prev *= 2; curr *= 2; ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
