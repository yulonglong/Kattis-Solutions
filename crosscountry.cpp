// https://open.kattis.com/problems/crosscountry

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define INF 2e9
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> adjList;
vector<int> dist;

struct Node {
    int v;
    int cost;
    Node() {}
    Node(int newV, int newCost) {
        v = newV;
        cost = newCost;
    }
    bool operator()(const Node& lhs, const Node& rhs) {
        return lhs.cost > rhs.cost;
    }
};

void dijkstra(int source) {
    priority_queue<Node, vector<Node>, Node> pq;
    Node firstNode(source, 0);
    dist[source] = 0;
    pq.push(firstNode);
    while (!pq.empty()) {
        int v = pq.top().v;
        int cost = pq.top().cost;
        pq.pop();
        if (cost > dist[v]) continue;
        for (int i = 0; i < adjList[v].size(); i++) {
            int dest = adjList[v][i].first;
            int destCost = adjList[v][i].second;
            if (cost + destCost < dist[dest]) {
                dist[dest] = cost + destCost;
                Node nextNode(dest, cost + destCost);
                pq.push(nextNode);
            }
        }
    }
}

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    adjList.assign(n, vii());
    dist.assign(n, INF);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            cin >> cost;
            adjList[i].push_back(ii(j, cost));
        }
    }
    dijkstra(s);
    cout << dist[t] << endl;
    return 0;
}
