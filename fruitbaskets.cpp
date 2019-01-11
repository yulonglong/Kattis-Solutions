// https://open.kattis.com/problems/fruitbaskets

#include <bits/stdc++.h>
using namespace std;
#define MAX 41
typedef unsigned long long ull;

vector<ull> pascalTriangle[MAX];

void initPascalTriangle() {
	pascalTriangle[0].push_back(1);
	pascalTriangle[1].push_back(1);
	pascalTriangle[1].push_back(1);
	for (int i=2;i<MAX;i++) {
		pascalTriangle[i].push_back(1);
		for (int j=0;j<pascalTriangle[i-1].size()-1;j++){
			pascalTriangle[i].push_back(pascalTriangle[i-1][j] + pascalTriangle[i-1][j+1]);
		}
		pascalTriangle[i].push_back(1);
	}
}

int items[MAX];
int main() {
	initPascalTriangle();
	int N;
	cin >> N;
	ull sumAllItems = 0;
	for (int i = 0; i < N; i++) {
		cin >> items[i];
		sumAllItems += items[i];
	}

	// Compute manually the sum of all possible combination when there are 3 items or less
	ull total = 0;
	ull currSum = 0;
	for (int i = 0; i < N; i++) {
		currSum = items[i];
		if (currSum >= 200) total += currSum;
		for (int j = i + 1; j < N; j++) {
			currSum = items[i] + items[j];
			if (currSum >= 200) total += currSum;
			for (int k = j + 1; k < N; k++) {
				currSum = items[i] + items[j] + items[k];
				if (currSum >= 200) total += currSum;
			}
		}
	}
	// Get all the sum for 4 items onwards
	for (int i = 3; i < pascalTriangle[N-1].size(); i++) {
		total += sumAllItems * pascalTriangle[N-1][i];
	}
	cout << total << endl;
	return 0;
}
