// https://open.kattis.com/problems/muddyhike

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 2e9

int grid[MAX][MAX];
int dist[MAX][MAX];
int r, c;

void initDist() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dist[i][j] = INF;
		}
	}
}

struct Node {
	int x;
	int y;
	int cost;
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

void dijkstraWithAllStartNodes() {
	priority_queue<Node, vector<Node>, Node> pq;
	// Push all possible starting nodes to priority queue
	for (int i=0;i<r;i++){
		int j = 0;
		Node firstNode(i, j, grid[i][j]);
		dist[i][j] = grid[i][j];
		pq.push(firstNode);
	}
	
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cost = pq.top().cost;
		// cout << x << " " << y << " " << cost << endl;
		pq.pop();
		if (cost > dist[x][y])
			continue;

		if (x - 1 >= 0) {
			if (max(grid[x - 1][y],cost) < dist[x - 1][y]) {
				dist[x - 1][y] = max(grid[x - 1][y],cost);
				Node currNode(x - 1, y, dist[x - 1][y]);
				pq.push(currNode);
			}
		}
		if (x + 1 < r) {
			if (max(grid[x + 1][y],cost) < dist[x + 1][y]) {
				dist[x + 1][y] = max(grid[x + 1][y],cost);
				Node currNode(x + 1, y, dist[x + 1][y]);
				pq.push(currNode);
			}
		}
		if (y - 1 >= 0) {
			if (max(grid[x][y - 1],cost) < dist[x][y - 1]) {
				dist[x][y - 1] = max(grid[x][y - 1],cost);
				Node currNode(x, y - 1, dist[x][y - 1]);
				pq.push(currNode);
			}
		}
		if (y + 1 < c) {
			if (max(grid[x][y + 1],cost) < dist[x][y + 1]) {
				dist[x][y + 1] = max(grid[x][y + 1],cost);
				Node currNode(x, y + 1, dist[x][y + 1]);
				pq.push(currNode);
			}
		}
	}
}

int main() {
	memset(grid, 0, sizeof(grid));
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

	int globalMin = INF;
	initDist();
	dijkstraWithAllStartNodes();

	for (int j = 0; j < r; j++) {
		globalMin = min(globalMin, dist[j][c - 1]);
	}
	
	cout << globalMin << endl;

	return 0;
}
