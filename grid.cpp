// https://open.kattis.com/problems/grid

#include <bits/stdc++.h>
using namespace std;
#define MAX 500
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

char grid[MAX][MAX];
int h, w;
ii d[4] = {ii(0, 1), ii(1, 0), ii(-1, 0), ii(0, -1)};

int getGridValue(int x, int y) {
	return grid[x][y] - '0';
}

int bfs() {
	bool visited[MAX][MAX];
	memset(visited, false, sizeof(visited));
	queue<iii> q;
	q.push(make_pair(ii(0, 0), 0));
	visited[0][0] = true;
	while (!q.empty()) {
		int cost = q.front().second;
		ii pt = q.front().first;
		int x = pt.first;
		int y = pt.second;
		q.pop();
		int currGrid = getGridValue(x, y);
		for (int i = 0; i < 4; i++) {
			int nextX = x + (d[i].first * currGrid);
			int nextY = y + (d[i].second * currGrid);
			if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w) {
				if (!visited[nextX][nextY]) {
					visited[nextX][nextY] = true;
					q.push(make_pair(ii(nextX,nextY),cost+1));
					if (nextX == h-1 && nextY == w-1) return cost+1;
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> grid[i][j];
		}
	}
	cout << bfs() << endl;

	return 0;
}
