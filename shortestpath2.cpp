// https://open.kattis.com/problems/shortestpath2

#include <cstdio>
#include <vector>
#include <queue>
#define MAX 30100
#define INF 2000000000
using namespace std;



struct Node {
	int vertex;
	int t;
	int p;
	int cost;
	bool operator()(const Node& lhs, const Node& rhs) {
		return lhs.cost > rhs.cost;
	}
	Node(int _vertex, int _t, int _p, int _cost) {
		vertex = _vertex;
		t = _t;
		p = _p;
		cost = _cost;
	}
	Node() {
		vertex = 0;
		cost = 0;
		t = 0;
		p = 0;
	}
};

vector<Node> adjList[MAX];
int cost[MAX];

void init() {
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
		cost[i] = INF;
	}
	return;
}


void dijkstra(int start) {
	priority_queue<Node, vector<Node>, Node> pq;
	pq.push(Node(start,0,0,0));

	while (!pq.empty()) {
		Node currNode = pq.top(); pq.pop();
		int currVertex = currNode.vertex;
		int currCost = currNode.cost;
		if (cost[currVertex] < currCost) continue;
		cost[currVertex] = currCost;

		for(int i=0;i<adjList[currVertex].size();i++){
			int currPossibleCost = currCost;
			if (currCost < adjList[currVertex][i].t) {
				currPossibleCost = adjList[currVertex][i].t;
			}
			else if (currCost > adjList[currVertex][i].t) {
				if (adjList[currVertex][i].p == 0) continue;
				int diff = currCost - adjList[currVertex][i].t;
				int multiplier = diff / adjList[currVertex][i].p;
				if (diff % adjList[currVertex][i].p > 0)
					multiplier++;
				currPossibleCost = adjList[currVertex][i].t + (adjList[currVertex][i].p*multiplier);
			}

			if (currPossibleCost + adjList[currVertex][i].cost < cost[adjList[currVertex][i].vertex]) {
				pq.push(Node(adjList[currVertex][i].vertex,0,0,currPossibleCost + adjList[currVertex][i].cost));
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
			int from, to, t,p, weight;
			scanf("%d %d %d %d %d", &from, &to, &t, &p, &weight);
			adjList[from].push_back(Node(to,t,p,weight));
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
