// https://open.kattis.com/problems/paintball

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vi match, vis;

int Aug(int l) {                 // return 1 if an augmenting path is found
	if (vis[l]) return 0;                               // return 0 otherwise
	vis[l] = 1;
	for (int j = 0; j < (int)AdjList[l].size(); j++) {
		int r = AdjList[l][j];
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
	} }
	return 0;
}

int main() {
	int Vleft, m;
	scanf("%d %d",&Vleft,&m);
	int V = 2*Vleft;
	AdjList.assign(V, vi());
	while (m--) {
		int from, to; scanf("%d %d",&from,&to);
		from--; to--;
		AdjList[from].push_back(to+Vleft);
		AdjList[to].push_back(from+Vleft);
	}

	int MCBM = 0;
	match.assign(V, -1);    // V is the number of vertices in bipartite graph
	for (int l = 0; l < Vleft; l++) {         // Vleft = size of the left set
		vis.assign(Vleft, 0);                    // reset before each recursion
		MCBM += Aug(l);
	}
	if (MCBM < Vleft) printf("Impossible\n");
	else {
		// printf("Found %d matchings\n", MCBM);  // the answer is 2 for Figure 4.42
		for(int i=Vleft;i<V;i++){
			printf("%d\n",match[i]+1);
		}
	}
	return 0;
}
