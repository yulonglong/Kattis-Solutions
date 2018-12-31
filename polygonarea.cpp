// https://open.kattis.com/problems/polygonarea

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
typedef pair<int, int> ii;
typedef unsigned long long ull;

ii coord[MAX];

int main() {
	int n;
	while (cin >> n && n > 0) {
		for (int i = 0; i < n; i++) {
			cin >> coord[i].first >> coord[i].second;
		}
		long long sumPos = 0;
		long long sumNeg = 0;
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			sumPos += coord[i].first * coord[j].second;
			sumNeg += coord[i].second * coord[j].first;
		}
		double area = (sumPos - sumNeg) / 2.0;

		if (area < 0.0)
			printf("CW %.1f\n", -area);
		else 
			printf("CCW %.1f\n", area);
		
	}
	return 0;
}
