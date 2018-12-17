// https://open.kattis.com/problems/millionairemadness

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 2e9
int grid[MAX][MAX];
int dist[MAX][MAX];
int r, c;

struct Node {
	int x, y, cost;
	Node() {}
	Node(int newX, int newY, int newCost) {
		x = newX;
		y = newY;
		cost = newCost;
	}
	bool operator()(const Node &lhs, const Node &rhs) {
		return lhs.cost > rhs.cost;
	}
};

int dijkstra() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			dist[i][j] = INF;
	dist[0][0] = 0;
	priority_queue<Node, vector<Node>, Node> pq;
	Node start(0, 0, 0);
	pq.push(start);
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cost = pq.top().cost;
		pq.pop();
		if (cost > dist[x][y])
			continue;
		if (x - 1 >= 0) {
			int newCost = grid[x - 1][y] - grid[x][y];
			if (newCost <= 0) newCost = 0;
			newCost = max(newCost,cost);
			if (newCost < dist[x - 1][y]) {
				dist[x - 1][y] = newCost;
				pq.push(Node(x - 1, y, newCost));
			}
		}
		if (x + 1 < r) {
			int newCost = grid[x + 1][y] - grid[x][y];
			if (newCost <= 0) newCost = 0;
			newCost = max(newCost,cost);
			if (newCost < dist[x + 1][y]) {
				dist[x + 1][y] = newCost;
				pq.push(Node(x + 1, y, newCost));
			}
		}
		if (y - 1 >= 0) {
			int newCost = grid[x][y - 1] - grid[x][y];
			if (newCost <= 0) newCost = 0;
			newCost = max(newCost,cost);
			if (newCost < dist[x][y - 1]) {
				dist[x][y - 1] = newCost;
				pq.push(Node(x, y - 1, newCost));
			}
		}
		if (y + 1 < c) {
			int newCost = grid[x][y + 1] - grid[x][y];
			if (newCost <= 0) newCost = 0;
			newCost = max(newCost,cost);
			if (newCost < dist[x][y + 1]) {
				dist[x][y + 1] = newCost;
				pq.push(Node(x, y + 1, newCost));
			}
		}
	}
	return dist[r - 1][c - 1];
}

int main() {
	memset(grid, 0, sizeof(grid));
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> grid[i][j];

	cout << dijkstra() << endl;
	// for (int i = 0; i < r; i++) {
	// 	for (int j = 0; j < c; j++)
	// 		cout << dist[i][j] << " ";
	// 	cout << endl;	
	// }
	// cout << r-1 << "." << c-1 << endl;
	return 0;
}
