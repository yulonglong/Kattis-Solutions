// https://open.kattis.com/problems/pot

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
	int n;
	cin >> n;
	ull total = 0;
	while (n--) {
		ull num;
		cin >> num;
		ull power = num % 10;
		num /= 10;
		total += pow(num, power);
	}
	cout << total << endl;
	return 0;
}
