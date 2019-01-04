// https://open.kattis.com/problems/reachableroads

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<int> adjList[MAX];
int visited[MAX];

void clearAdjList() {
	for (int i=0;i<MAX;i++) {
		adjList[i].clear();
	}
}

int completeBfs(int n) {
	int numComponents = 0;
	memset(visited, false, sizeof(visited));
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			numComponents++;
			visited[i] = true;
			q.push(i);

			// The real BFS
			while (!q.empty()) {
				int x = q.front(); q.pop();
				for (int y : adjList[x]) {
					if (!visited[y]) {
						visited[y] = true;
						q.push(y);
					}
				}
			}
		}
	}
	return numComponents;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		clearAdjList();
		int n; cin >> n;
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		int numComponents = completeBfs(n);
		cout << numComponents-1 << endl;
	}
	return 0;
}
