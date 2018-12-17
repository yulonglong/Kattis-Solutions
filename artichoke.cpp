// https://open.kattis.com/problems/artichoke

#include <bits/stdc++.h>
#define MAX 1001001
using namespace std;

double p,a,b,c,d;
int n;
double price(double k) {
	return p*(sin(a*k+b) + cos(c*k+d)+2.0);
}

double diff[MAX];

int main() {
	cin >> p >> a >> b  >> c >> d >> n;
	// cout << p << " "<< a << " " << b << " " << c << " " << d << " " << n << endl;

	double currPrice = price(1.0);
	double prevPrice = currPrice;
	for (int i=2;i<=n;i++) {
		currPrice = price((double)i);
		diff[i-2] = prevPrice - currPrice;
		prevPrice = currPrice;
	}

	// Longest Sum Subarray
	double largestSum = 0.0;
	double sum = 0.0;
	for (int i=0;i<n-1;i++) {
		sum += diff[i];
		if (sum > largestSum) largestSum = sum;
		if (sum < 0) sum = 0.0;
	}
	printf("%.6f\n", largestSum);
	return 0;
}
