// https://open.kattis.com/problems/unionfind

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
	private:
		vector<int> p, rank;
	public:
		UnionFind(int N) {
			p.assign(N,0);
			rank.assign(N,0);
			for(int i=0;i<N;i++){
				p[i] = i;
			}
		}
		int findSet(int i) {
			if (p[i] == i) return i;
			else return p[i] = findSet(p[i]);
		}
		int unionSet(int i, int j) {
			int x = findSet(i);
			int y = findSet(j);
			if (x != y) {
				if (rank[x] > rank[y]) {
						p[y] = x;
				}
				else {
					p[x] = y;
					if (rank[x]==rank[y]) rank[y]++;
				}
			}
		}
};

int main() {
	int n, q; scanf("%d %d\n",&n, &q);
	UnionFind ufds(n);
	while (q--) {
		char op; int a,b;
		scanf("%c %d %d\n",&op,&a,&b);
		if (op == '=') ufds.unionSet(a,b);
		else {
			if (ufds.findSet(a) == ufds.findSet(b)) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
