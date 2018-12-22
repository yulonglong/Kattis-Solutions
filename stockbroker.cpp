// https://open.kattis.com/problems/stockbroker

#include <bits/stdc++.h>
using namespace std;
#define MAX 366
typedef unsigned long long ull;

int price[MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> price[i];

	ull money = 100;
	for (int i = 1; i < n; i++) {
		if (price[i - 1] < price[i]) {
			ull buyableStock = money / price[i - 1];
			if (buyableStock > 100000) buyableStock = 100000;
			money -= buyableStock * price[i - 1];
			money += buyableStock * price[i];
		}
	}
	cout << money << endl;
	return 0;
}
