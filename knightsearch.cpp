// https://open.kattis.com/problems/knightsearch

#include <bits/stdc++.h>
using namespace std;
#define MAX 101
typedef pair<int, int> ii;

char grid[MAX][MAX];
vector<ii> iCoord;
bool found = false;

int mvx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int mvy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

void dfs(ii start, const string& target, int idx, int n) {
	int x = start.first;
	int y = start.second;
	if (idx == target.length()) {
		found = true;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nextX = x + mvx[i];
		int nextY = y + mvy[i];
		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
			if (grid[nextX][nextY] == target[idx]) {
				dfs(make_pair(nextX, nextY), target, idx + 1, n);
			}
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'I') iCoord.push_back(make_pair(i, j));
		}
	}
	string target = "ICPCASIASG";
	for (int i = 0; i < iCoord.size(); i++) {
		dfs(iCoord[i], target, 1, n);
		if (found) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
