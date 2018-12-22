// https://open.kattis.com/problems/woodcutting

#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

double cust[MAX];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		memset(cust, 0, sizeof(cust));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int w;
			scanf("%d", &w);
			for (int j = 0; j < w; j++) {
				double temp;
				scanf("%lf", &temp);
				cust[i] += temp;
			}
		}
		sort(cust, cust + n);
		double currSum = 0.0;
		double wait = 0.0;
		for (int i = 0; i < n; i++) {
			currSum += cust[i];
			wait += currSum;
		}
		wait = wait / (double)n;
		printf("%.7f\n", wait);
	}
	return 0;
}
