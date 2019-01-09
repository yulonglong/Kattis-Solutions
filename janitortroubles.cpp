// https://open.kattis.com/problems/janitortroubles

#include <bits/stdc++.h>
using namespace std;

int main() {
	double a,b,c,d; cin >> a >> b >> c >> d;
	double p = (a+b+c+d)/2.0;
	double area = sqrt((p-a)*(p-b)*(p-c)*(p-d));
	printf("%.6f\n",area);
	return 0;
}
