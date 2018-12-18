// https://open.kattis.com/problems/sellingspatulas

#include <bits/stdc++.h>
using namespace std;
#define MAX 1440
#define EPS 1e-9

double sale[MAX];

void clearSale() {
	for (int i = 0; i < MAX; i++) {
		sale[i] = -0.08;
	}
}

int main() {
	int n;
	while (cin >> n && n != 0) {
		clearSale();
		for (int i = 0; i < n; i++) {
			int t; double profit;
			cin >> t >> profit;
			sale[t] += profit;
		}
		double globalProfit = 0.0;
		int globalDuration = 0;
		int globalStartTime = 0;
		double currSum = 0.0;
		int currDuration = 0;
		int startTime = 0;
		for (int i = 0; i < MAX; i++) {
			currSum += sale[i];
			if (currSum < EPS) {
				currSum = 0.0;
				currDuration = 0;
				startTime = i + 1;
			}
			else {
				currDuration++;
			}
			if ((currSum - globalProfit) > EPS) {
				globalProfit = currSum;
				globalDuration = currDuration;
				globalStartTime = startTime;
			}
			else if (fabs(currSum - globalProfit) < EPS) {
				if (currDuration < globalDuration) {
					globalStartTime = startTime;
					globalDuration = currDuration;
				}
			}
		}
		if (globalProfit < EPS)
			printf("no profit\n");
		else
			printf("%.2f %d %d\n", globalProfit, globalStartTime, globalStartTime + globalDuration - 1);
	}
	return 0;
}
