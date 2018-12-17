// https://open.kattis.com/problems/10kindsofpeople

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
typedef pair<int,int> ii;

class UnionFind {
	private:
		vector<int> p;
		vector<int> rank;
	public:
		UnionFind(int n){
			p.assign(n,0);
			rank.assign(n,0);
			for (int i=0;i<n;i++){
				p[i] = i;
			}
		}

		int findSet(int i) {
			if (p[i] == i) return i;
			else return p[i] = findSet(p[i]);
		}

		bool isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}

		void unionSet(int i, int j) {
			i = findSet(i); j = findSet(j);
			if (i != j) {
				if (rank[i] > rank[j]) {
					p[j] = i;
				}
				else {
					p[i] = j;
					if (rank[i] == rank[j]) rank[j]++;
				}
			}
		}
};

UnionFind ufds(MAX*MAX);
char grid[MAX][MAX];
int visited[MAX][MAX];
int r,c; 

char bfs(int x1, int y1) {
	char flavor = grid[x1][y1];
	visited[x1][y1] = 1;
	queue<ii> q;
	q.push(ii(x1,y1));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x+1 < r) {
			if (grid[x+1][y] == flavor && visited[x+1][y] == 0) {
				visited[x+1][y] = 1;
				ufds.unionSet(x*1000+y,(x+1)*1000+y);
				q.push(ii(x+1,y));
			}
		}
		if (x-1 >= 0) {
			if (grid[x-1][y] == flavor && visited[x-1][y] == 0) {
				visited[x-1][y] = 1;
				ufds.unionSet(x*1000+y,(x-1)*1000+y);
				q.push(ii(x-1,y));
			}
		}
		if (y+1 < c) {
			if (grid[x][y+1] == flavor && visited[x][y+1] == 0) {
				visited[x][y+1] = 1;
				ufds.unionSet(x*1000+y,x*1000+y+1);
				q.push(ii(x,y+1));
			}
		}
		if (y-1 >= 0) {
			if (grid[x][y-1] == flavor && visited[x][y-1] == 0) {
				visited[x][y-1] = 1;
				ufds.unionSet(x*1000+y,x*1000+y-1);
				q.push(ii(x,y-1));
			}
		}
	}
	return -1;
}

int main() {
	memset(visited,0,sizeof(visited));
	memset(grid,0,sizeof(grid));
	// scanf("%d",&r,&c);
	cin >> r >> c;
	for (int i=0;i<r;i++) {
		for (int j=0;j<c;j++) {
			char c; cin >> c;
			grid[i][j] = c;
		}
	}
	int n;
	cin >> n;
	// scanf("%d",&n);


	for (int i=0;i<r;i++) {
		for (int j=0;j<c;j++) {
			if (visited[i][j] == 0) {
				bfs(i,j);
			}
		}
	}


	for (int i=0;i<n;i++) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (!ufds.isSameSet((x1-1)*1000+(y1-1), (x2-1)*1000+(y2-1))) {
			cout << "neither" << endl;
		}
		else {
			char flavor = grid[x1-1][y1-1];
			if (flavor == '1') {
				cout << "decimal" << endl;
			}
			else if (flavor == '0') {
				cout << "binary" << endl;
			}
		}
	}


	return 0;
}
