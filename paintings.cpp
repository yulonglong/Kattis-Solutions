// https://open.kattis.com/problems/paintings

#include <bits/stdc++.h>
using namespace std;
#define MAX 13

unordered_map<string, int> dat;
unordered_map<string, int>::iterator iter1;
string reverseDat[MAX];
int adjMatrix[MAX][MAX];
int N;

int total = 0;
vector<int> sequence;
int visited[MAX];

void dfs(int x, vector<int>& currSequence) {
	visited[x] = true;
	currSequence.push_back(x);
	if (currSequence.size() == N) {
		total += 1;
		if (sequence.size() == 0) {
			sequence = currSequence;
		}
	} else {
		for (int i = 0; i < N; i++) {
			// cannot go to the same vertex, cannot go forbidden edges, cannot go already visited vertex
			if (x != i && adjMatrix[x][i] == 0 && !visited[i]) {
				dfs(i, currSequence);
			}
		}
	}
	visited[x] = false;
	currSequence.pop_back();
	return;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		total = 0;
		sequence.clear();
		dat.clear();
		// 0 represents have edge
		memset(adjMatrix, 0, sizeof(adjMatrix));
		cin >> N;
		for (int i = 0; i < N; i++) {
			string color;
			cin >> color;
			reverseDat[i] = color;
			dat.insert(make_pair(color, i));
		}
		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			string color1, color2;
			cin >> color1 >> color2;
			int x = dat[color1];
			int y = dat[color2];
			// 1 represent restriction, no edge
			adjMatrix[x][y] = 1;
			adjMatrix[y][x] = 1;
		}

		// Solve it now
		memset(visited,false,sizeof(visited));
		vector<int> tempContainer;
		for (int i=0;i<N;i++) 
			dfs(i, tempContainer);

		cout << total << endl;
		cout << reverseDat[sequence[0]];
		for (int i = 1; i < N; i++) cout << " " << reverseDat[sequence[i]];
		cout << endl;
	}

	return 0;
}
