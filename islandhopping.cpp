// https://open.kattis.com/problems/islandhopping

#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> dd;
#define MAX 751

dd islands[MAX];
double adjMatrix[MAX][MAX];

double getDistance(dd pt1, dd pt2) {
	// Euclidean Distance
	double x1 = pt1.first;
	double y1 = pt1.second;
	double x2 = pt2.first;
	double y2 = pt2.second;
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void initAdjMatrix(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				adjMatrix[i][j] = 0;
			else
				adjMatrix[i][j] = getDistance(islands[i], islands[j]);
		}
	}
}

struct Node {
	int x;
	double cost;
	Node() {}
	Node(int _x, double _cost) {
		x = _x;
		cost = _cost;
	}
	bool operator()(const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
};

double mst(int n) {
	// prims
	bool visited[MAX];
	memset(visited, false, sizeof(visited));

	double totalCost = 0.0;
	int countVisited = 0;

	priority_queue<Node, vector<Node>, Node> pq;
	pq.push(Node(0, 0.0));
	while (!pq.empty()) {
		int x = pq.top().x;
		double cost = pq.top().cost;
		pq.pop();
		if (visited[x]) continue;
		visited[x] = true;
		countVisited += 1;
		totalCost += cost;
		if (countVisited == n) break;
		for (int j = 0; j < n; j++) {
			if (!visited[j]) {
				pq.push(Node(j, adjMatrix[x][j]));
			}
		}
	}
	return totalCost;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			double a, b;
			cin >> a >> b;
			islands[i] = make_pair(a, b);
		}

		initAdjMatrix(n);
		double cost = mst(n);
		printf("%.4f\n", cost);
	}
	return 0;
}
