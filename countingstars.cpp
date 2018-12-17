// https://open.kattis.com/problems/countingstars

#include <bits/stdc++.h>
using namespace std;
#define MAX 101

char grid[MAX][MAX];
bool visited[MAX][MAX];
int r, c;

void dfs(int x, int y) {
	if (x - 1 >= 0) {
		if (grid[x - 1][y] == '-' && !visited[x - 1][y]) {
			visited[x - 1][y] = true;
			dfs(x - 1, y);
		}
	}
	if (x + 1 < r) {
		if (grid[x + 1][y] == '-' && !visited[x + 1][y]) {
			visited[x + 1][y] = true;
			dfs(x + 1, y);
		}
	}
	if (y - 1 >= 0) {
		if (grid[x][y - 1] == '-' && !visited[x][y - 1]) {
			visited[x][y - 1] = true;
			dfs(x, y - 1);
		}
	}
	if (y + 1 < c) {
		if (grid[x][y + 1] == '-' && !visited[x][y + 1]) {
			visited[x][y + 1] = true;
			dfs(x, y + 1);
		}
	}
}

int main() {
	int tc = 1;
	while (cin >> r >> c) {
		memset(grid, 0, sizeof(grid));
		memset(visited, false, sizeof(visited));
		int count = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> grid[i][j];
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == '-' && !visited[i][j]) {
					count++;
					visited[i][j] = true;
					dfs(i, j);
				}
			}
		}

		cout << "Case " << tc++ << ": " << count << endl;
	}

	return 0;
}
