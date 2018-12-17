// https://open.kattis.com/problems/character

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	cout << ((1 << n) - n -1) << endl;
	return 0;
}
