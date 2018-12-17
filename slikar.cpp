// https://open.kattis.com/problems/slikar

#include <bits/stdc++.h>
using namespace std;
#define MAX 51
#define SOURCE -5
#define OBS -3
#define INF 2e9
#define DEST 2e9+10
typedef pair<int, int> ii;

int grid[MAX][MAX];
bool visited[MAX][MAX];
ii source;
ii dest;

struct Triplets {
	int first, second, third;
	Triplets() {}
	Triplets(int a, int b, int c) {
		first = a;
		second = b;
		third = c;
	}
};

int main() {
	memset(grid, -1, sizeof(grid));
	memset(visited, false, sizeof(visited));
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char temp;
			cin >> temp;
			if (temp == 'D') {
				grid[i][j] = DEST;
				dest.first = i; dest.second = j;
			}
			else if (temp == 'S') {
				grid[i][j] = SOURCE;
				source.first = i; source.second = j;
			}
			else if (temp == 'X')
				grid[i][j] = OBS;
			else if (temp == '*')
				grid[i][j] = 0;
			else
				grid[i][j] = INF;
		}
	}

	// flood the map
	for (int v = 0; v <= MAX; v++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == v) {
					if ((i + 1 < r) && grid[i + 1][j] == INF)
						grid[i + 1][j] = v + 1;
					if ((i - 1 >= 0) && grid[i - 1][j] == INF)
						grid[i - 1][j] = v + 1;
					if ((j + 1 < c) && grid[i][j + 1] == INF)
						grid[i][j + 1] = v + 1;
					if ((j - 1 >= 0) && grid[i][j - 1] == INF)
						grid[i][j - 1] = v + 1;
				}
			}
		}
	}

	// BFS
	queue<Triplets> q;
	visited[source.first][source.second] = true;
	q.push(Triplets(source.first, source.second, 0));

	int answer = -1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cost = q.front().third;
		if (x == dest.first && y == dest.second) {
			answer = cost;
			break;
		}
		q.pop();

		if (x + 1 < r && !visited[x + 1][y] && grid[x + 1][y] >= 0 && cost + 1 < grid[x + 1][y]) {
			visited[x + 1][y] = true;
			Triplets nextTriplets(x + 1, y, cost + 1);
			q.push(nextTriplets);
		}
		if (x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] >= 0 && cost + 1 < grid[x - 1][y]) {
			visited[x - 1][y] = true;
			Triplets nextTriplets(x - 1, y, cost + 1);
			q.push(nextTriplets);
		}
		if (y + 1 < c && !visited[x][y + 1] && grid[x][y + 1] >= 0 && cost + 1 < grid[x][y + 1]) {
			visited[x][y + 1] = true;
			Triplets nextTriplets(x, y + 1, cost + 1);
			q.push(nextTriplets);
		}
		if (y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] && cost + 1 < grid[x][y - 1]) {
			visited[x][y - 1] = true;
			Triplets nextTriplets(x, y - 1, cost + 1);
			q.push(nextTriplets);
		}
	}

	if (answer == -1)
		cout << "KAKTUS" << endl;
	else
		cout << answer << endl;

	return 0;
}
