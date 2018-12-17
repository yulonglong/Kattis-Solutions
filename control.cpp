// https://open.kattis.com/problems/control

#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
	vi p, rank, setSize;                       // remember: vi is vector<int>
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) { 
		if (!isSameSet(i, j)) { numSets--; 
		int x = findSet(i), y = findSet(j);
		// rank is used to keep the tree short
		if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else                   { p[x] = y; setSize[y] += setSize[x];
														 if (rank[x] == rank[y]) rank[y]++; } } }
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
	int answer = 0;

	int n;
	scanf("%d",&n);
	UnionFind UF(500100);

	while(n--){
		int m, temp;
		vi ingrd;
		scanf("%d",&m);
		while (m--){
			scanf("%d",&temp);
			ingrd.push_back(temp);
		}

		map<int,int> freq;
		freq.clear();
		map<int,int>::iterator it;
		map<int,int>::iterator itNext;

		for(int i=0;i<ingrd.size();i++){
			int parent = UF.findSet(ingrd[i]);
			it = freq.find(parent);
			if (it == freq.end()) {
				freq.insert(pair<int,int>(parent,1));
			}
			else {
				it->second += 1;
			}
		}

		bool valid = true;
		for(it = freq.begin(); it != freq.end(); it++ ) {
			int requiredSize = UF.sizeOfSet(it->first);
			if (requiredSize != it->second) {
				valid = false;
				break;
			}
		}
		if (valid) {
			answer++;
			
			it = freq.begin();
			itNext = freq.begin();
			itNext++;

			for(; itNext != freq.end(); it++,itNext++ ) {
				UF.unionSet(it->first, itNext->first);
			}
		}
	}
	printf("%d\n",answer);
	return 0;
}
