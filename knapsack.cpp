// https://open.kattis.com/problems/knapsack

#include <bits/stdc++.h>
using namespace std;
#define MAX 2005
typedef pair<int, int> ii;

int memo[MAX][MAX];
int c, n;
ii items[MAX];
int p[MAX];
int ans[MAX];

// Top Down DP
int dp(int capacity, int state) {
	if (capacity > c)
		return -2000000000;
	if (state == n)
		return 0;
	if (memo[capacity][state] != -1)
		return memo[capacity][state];
	int noTake = dp(capacity, state + 1);
	int take = dp(capacity + items[state].second, state + 1) + items[state].first;
	if (take > noTake) {
		p[state+1] = state;
		return memo[capacity][state] = take;
	}
	return memo[capacity][state] = noTake;
}

// Bottom Up DP
int bottomUpDp() {
	for (int j=0;j<=c;j++){
		memo[j][0] = 0;
	}

	for (int i=1;i<=n;i++){
		int currValue = items[i-1].first;
		int currWeight = items[i-1].second;
		for (int j=0;j<=c;j++){
			int prevCapacity = j - currWeight;
			if (prevCapacity >= 0 && memo[prevCapacity][i-1] + currValue > memo[j][i-1]) {
				memo[j][i] = memo[prevCapacity][i-1] + currValue;
			}
			else {
				memo[j][i] = memo[j][i-1];
			}
		}
	}

	int currMaxValue = -20000;
	int x;
	for (int j=0;j<=c;j++) {
		// cout << memo[j][n] << " ";
		if (currMaxValue < memo[j][n]) {
			currMaxValue = memo[j][n];
			x = j;
		}
	}
	// cout << "::: " <<  x << endl;
	
	// Backtracking through answers
	if (currMaxValue == 0) {
		printf("0\n");
		return currMaxValue;
	}
	vector<int> ans;
	int idx = n;
	while (idx > 0) { // Need compare with -1 because did not put first state as 0
		int prevCapacity = x - items[idx-1].second;
		if (prevCapacity >= 0) {
			int prevState = 0;
			if (idx-1 >= 0) {
				prevState = memo[prevCapacity][idx-1];
			}
			if ((memo[x][idx] - items[idx-1].first) == prevState) {
				ans.push_back(idx-1);
				x = prevCapacity;
			}
		}
		idx--;
	}
	cout << ans.size() << endl;
	printf("%d",ans[0]);
	for (int i=1;i<ans.size();i++) printf(" %d",ans[i]);
	printf("\n");
	
	return currMaxValue;
}

int main(){
	float floatC;
	while(scanf("%f %d",&floatC, &n) == 2) {
		c = floatC;
		memset(memo, -1, sizeof(memo));
		memset(p,-1,sizeof(p));
		for (int i = 0; i < n; i++) {
			int value, weight;
			scanf("%d %d",&value,&weight);
			items[i] = ii(value,weight);
		}
		// cout << bottomUpDp() << endl;
		// cout << dp(0,0) << endl;
		// dp(0,0);
		bottomUpDp();

		// for (int j=0;j<=c;j++){
		// 	for (int i=0;i<=n;i++){
		// 		cout << memo[j][i] << " ";
		// 	}
		// 	cout << endl;
		// }

		// memset(ans,0,sizeof(ans));
		// int size = 0;
		// int idx = p[n];
		// while (idx != -1) {
		// 	ans[size++] = idx;
		// 	idx = p[idx];
		// }
		// printf("%d\n", size);
		// printf("%d",ans[0]);
		// for (int i=1;i<size;i++) printf(" %d",ans[i]);
		// printf("\n");

		// for (int i = 0; i <= n; i++) {
		// 	cout << p[i] << " ";
		// }
		// cout << endl;
	}
	return 0;
}
