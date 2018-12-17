// https://open.kattis.com/problems/height

#include <bits/stdc++.h>
using namespace std;
#define MAX 20

int height[MAX];
int sorted[MAX];

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		memset(sorted, -1, sizeof(sorted));
		int k;
		cin >> k;
		for (int i = 0; i < MAX; i++) {
			cin >> height[i];
		}
		int count = 0;
		sorted[0] = height[0];
		for (int i = 1; i < MAX; i++) {
			int j;
			int curr = height[i];
			
			for (j= i-1; j >= 0; j--) {
				if (curr < sorted[j]) {
					sorted[j+1] = sorted[j];
					count++;
				}
				else {
					break;
				}

			}
			sorted[j+1] = curr;
		}
		// for (int i = 0; i < MAX; i++)
		// 	cout << height[i] << " ";
		// cout << endl;
		// for (int i = 0; i < MAX; i++)
		// 	cout << sorted[i] << " ";
		// cout << endl;
		cout << k << " " << count << endl;
	}
	return 0;
}
