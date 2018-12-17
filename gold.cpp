// https://open.kattis.com/problems/gold

#include <bits/stdc++.h>
using namespace std;
#define MAX 51
typedef pair<int, int> ii;

char grid[MAX][MAX];
bool visited[MAX][MAX];
int r, c;

int bfs(int x, int y) {
	int gold = 0;
	queue<ii> q;
	q.push(ii(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		if (grid[xx][yy] == 'G')
			gold++;

		bool trap = false;
		if ((xx + 1 < r) && (grid[xx + 1][yy] == 'T'))
			trap = true;
		if ((xx - 1 >= 0) && (grid[xx - 1][yy] == 'T'))
			trap = true;
		if ((yy + 1 < c) && (grid[xx][yy + 1] == 'T'))
			trap = true;
		if ((yy - 1 >= 0) && (grid[xx][yy - 1] == 'T'))
			trap = true;

		if (!trap) {
			if (xx + 1 < r) {
				if (!visited[xx + 1][yy] && grid[xx + 1][yy] != '#') {
					visited[xx + 1][yy] = true;
					q.push(ii(xx + 1, yy));
				}
			}
			if (xx - 1 >= 0) {
				if (!visited[xx - 1][yy] && grid[xx - 1][yy] != '#') {
					visited[xx - 1][yy] = true;
					q.push(ii(xx - 1, yy));
				}
			}
			if (yy + 1 < c) {
				if (!visited[xx][yy + 1] && grid[xx][yy + 1] != '#') {
					visited[xx][yy + 1] = true;
					q.push(ii(xx, yy + 1));
				}
			}
			if (yy - 1 >= 0) {
				if (!visited[xx][yy - 1] && grid[xx][yy - 1] != '#') {
					visited[xx][yy - 1] = true;
					q.push(ii(xx, yy - 1));
				}
			}
		}
	}
	return gold;
}

int main() {
	memset(grid, 0, sizeof(grid));
	memset(visited, 0, sizeof(visited));
	cin >> c >> r;
	int px, py;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'P') {
				px = i;
				py = j;
			}
		}
	}
	cout << bfs(px, py) << endl;

	return 0;
}
