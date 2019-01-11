// https://open.kattis.com/problems/blockcrusher

#include <bits/stdc++.h>
using namespace std;
#define MAXH 21
#define MAXW 61
#define INF 2e9
typedef pair<int, int> ii;

int h, w;
int grid[MAXH][MAXW];
ii p[MAXH][MAXW];
int dist[MAXH][MAXW];
// To move the grid
int mvx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int mvy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void init() {
	for (int i = 0; i < MAXH; i++) {
		for (int j = 0; j < MAXW; j++) {
			p[i][j] = ii(-1, -1);
			dist[i][j] = INF;
		}
	}
}

struct Node {
	int x, y, cost;
	Node() {}
	Node(int _x, int _y, int _cost) {
		x = _x;
		y = _y;
		cost = _cost;
	}
	bool operator()(const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
};

void dijkstra() {
	init();
	priority_queue<Node, vector<Node>, Node> pq;
	for (int j = 0; j < w; j++) {
		pq.push(Node(0, j, grid[0][j]));
		dist[0][j] = grid[0][j];
		p[0][j] = ii(-2, -2);  // Use -2 to indicate source vertex
	}
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cost = pq.top().cost;
		pq.pop();
		if (dist[x][y] < cost) continue;
		for (int i = 0; i < 8; i++) {
			int nextX = x + mvx[i];
			int nextY = y + mvy[i];
			if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w) {
				int nextCost = cost + grid[nextX][nextY];
				if (dist[nextX][nextY] > nextCost) {
					dist[nextX][nextY] = nextCost;
					p[nextX][nextY] = ii(x, y);
					pq.push(Node(nextX,nextY,nextCost));
				}
			}
		}
	}
}

void backtrackAnswer() {
	int minCost = INF;
	int minY = INF;
	for (int j = 0; j < w; j++) {
		if (minCost >= dist[h - 1][j]) {
			minCost = dist[h - 1][j];
			minY = j;
		}
	}
	int minX = h - 1;
	// Start backtracking and removing answers
	while (minX != -2) {
		grid[minX][minY] = -2;
		int tempX = minX;
		int tempY = minY;
		minX = p[tempX][tempY].first;
		minY = p[tempX][tempY].second;
	}
}

void printAnswer() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] >= 0) {
				cout << grid[i][j];
			} else
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	while (cin >> h >> w && h != 0) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char temp;
				cin >> temp;
				grid[i][j] = temp - '0';
			}
		}
		dijkstra();
		backtrackAnswer();
		printAnswer();
	}

	return 0;
}
