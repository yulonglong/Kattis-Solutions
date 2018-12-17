// https://open.kattis.com/problems/tractor

#include <iostream>
#include <cmath>
using namespace std;

long long pow(long long a, long long exponent) {
	long long ans = 1;
	for(int i=0;i<exponent;i++){
		ans *= a;
	}
	return ans;
}

long long sumPow(long long a, long long exponent, long long &ans) {
	long long sum = 0;
	ans = 1;
	for(int i=0;i<=exponent;i++){
		sum += ans;
		ans *= a;
	}
	return sum;
}

int main() {
	// long long test;
	// cout << sumPow(2, 2, test) << endl;
	// cout << test << endl;
	int tc; cin >> tc;
	while (tc--) {
		int a,b; cin >> a >> b;
		if (a>b) swap(a,b);
		long long count = 0;

		long long nextPow;

		long long completePow = (long long)log2(a+1);
		count = sumPow(2,completePow,nextPow);

		long long finalRepeatCount = nextPow-((nextPow-1) - a);

		if (nextPow-1 > b) {
			finalRepeatCount -= (nextPow-1 - b);
			count += finalRepeatCount;
			cout << count << endl;
		}
		else {
			while (nextPow-1 <= b) {
				count += finalRepeatCount;
				nextPow *= 2;
			}
			if (nextPow-1 > b) {
				finalRepeatCount -= (nextPow-1 - b);
				if (finalRepeatCount > 0)
					count += finalRepeatCount;
			}
			cout << count << endl;
		}
	}
	return 0;
}
