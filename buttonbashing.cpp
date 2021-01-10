// https://open.kattis.com/problems/buttonbashing

#include <bits/stdc++.h>
using namespace std;
#define MAX 3601
#define INF 2000000000
typedef pair<int, int> ii;

int visited[MAX];
vector<int> buttons;
int closestTarget;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n, t; cin >> n >> t;
        buttons.clear();
        for (int i=0;i<n;i++) {
            int timer; cin >> timer;
            buttons.push_back(timer);
        }
        memset(visited, -1, sizeof(visited));
        closestTarget = INF;

        queue<ii> q;
        // first is the current vertex number, i.e., [0,3600]
        // second is the number of steps to get there.
        q.push(ii(0,0)); 
        while (!q.empty()) {
            int vertex = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // if vertex is already visited we can skip this node because
            // in BFS it's guaranteed the second visit has longer steps.
            if (visited[vertex] != -1)  {
                continue;
            }
            visited[vertex] = steps;
            if (vertex == t) {
                closestTarget = vertex;
                break;
            } else if (vertex > t && vertex-t < closestTarget-t) {
                closestTarget = vertex;
            }
            for (int i=0;i<n;i++) {
                int diff = buttons[i];
                int destVertex = vertex + diff;
                if (destVertex <= 0) {
                    continue;
                } else if (destVertex > 3600) {
                    destVertex = 3600;
                }
                q.push(ii(destVertex,steps + 1));
            }
        }

        cout << visited[closestTarget] << " " << closestTarget-t << endl;
    }
    return 0;
}
