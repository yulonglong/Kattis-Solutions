// https://open.kattis.com/problems/blockgame2

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

bool isWin(ull a, ull b) {
	if (a < b) swap(a,b);
	if (a%b == 0) return true;
	if (a/b > 1) return true;
	return !isWin(b, a-b);
}


int main() {
	ull a, b; cin >> a >> b;
	if (isWin(a,b)) cout << "win" << endl;
	else cout << "lose" << endl;
	return 0;
}
