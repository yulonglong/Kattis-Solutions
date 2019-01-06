// https://open.kattis.com/problems/kutevi

#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int gcd(int a, int b) {
	if (b == 0) return a;
	if (a < b) swap(a, b);
	int c = a % b;
	return gcd(b, c);
}

int main() {
	int n, k;
	cin >> n >> k;
	int globalGcd = 360;
	for (int i = 0; i < n; i++) {
		int curr;
		cin >> curr;
		globalGcd = gcd(globalGcd, curr);
	}
	for (int i = 0; i < k; i++) {
		int curr;
		cin >> curr;
		if (curr % globalGcd == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
