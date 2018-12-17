// https://open.kattis.com/problems/shortestpath1

#include <cstdio>
#include <vector>
#include <queue>
#define MAX 30100
#define INF 2000000000
using namespace std;

vector<pair<int,int> > adjList[MAX];
int cost[MAX];

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
		cost[i] = INF;
	}
	return;
}


struct Node {
	int vertex;
	int cost;
	bool operator()(const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
	Node(int _vertex, int _cost) {
		vertex = _vertex;
		cost = _cost;
	}
	Node() {
		vertex = 0;
		cost = 0;
	}
};

void dijkstra(int start) {
	priority_queue<Node, vector<Node>, Node> pq;
	pq.push(Node(start,0));

	while (!pq.empty()) {
		Node currNode = pq.top(); pq.pop();
		int currVertex = currNode.vertex;
		int currCost = currNode.cost;
		if (cost[currVertex] < currCost) continue;
		cost[currVertex] = currCost;
		for(int i=0;i<adjList[currVertex].size();i++){
			int nextVertex = adjList[currVertex][i].first;
			int nextCost = adjList[currVertex][i].second;
			if (currCost + nextCost < cost[nextVertex]) {
				pq.push(Node(nextVertex,currCost+nextCost));
			}
		}
	}
}

int main() {
	int n,m,q,s;
	while (scanf("%d %d %d %d",&n,&m,&q,&s) == 4) {
		if (n==0 && m==0 && q==0 && s==0) break;
		init();
		for (int i=0;i<m;i++) {
			int from, to, weight;
			scanf("%d %d %d", &from, &to, &weight);
			adjList[from].push_back(pair<int,int>(to,weight));
		}
		dijkstra(s);
		for (int i=0;i<q;i++){
			int target;
			scanf("%d",&target);
			if (cost[target] == INF) printf("Impossible\n");
			else printf("%d\n", cost[target]);
		}
		printf("\n");
	}
	return 0;
}
