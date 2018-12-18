// https://open.kattis.com/problems/commercials

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	long long currSum = 0;
	long long maxSum = 0;
	while (n--) {
		int curr;
		scanf("%d", &curr);
		currSum += (curr - p);
		if (currSum < 0) currSum = 0;
		maxSum = max(maxSum, currSum);
	}
	printf("%lld\n", maxSum);
	return 0;
}
