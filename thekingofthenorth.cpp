// https://open.kattis.com/problems/thekingofthenorth

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 200100

#define INF 2000000000

struct flow_network {

    struct edge {
        int u, v, cap;
        edge *rev;
        bool forward;
        edge(int _u, int _v, int _cap, bool forw)
            : u(_u), v(_v), cap(_cap), forward(forw) { }
    };

    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }

    void add_edge(int u, int v, int cap) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->rev = rev;
        rev->rev = e;
        adj[u].push_back(e);
        adj[v].push_back(rev);
    }

    int augment(int s, int t) {
        vector<edge*> back(n, (edge*)0);
        queue<int> Q;
        Q.push(s);
        back[s] = (edge*)1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i]->v;
                if (back[v] == NULL && adj[u][i]->cap > 0) {
                    back[v] = adj[u][i];
                    Q.push(v);
                }
            }
        }

        if (back[t] == NULL)
            return 0;

        stack<edge*> S;
        S.push(back[t]);
        int bneck = back[t]->cap;
        while (S.top()->u != s) {
            S.push(back[S.top()->u]);
            bneck = min(bneck, S.top()->cap);
        }

        while (!S.empty()) {
            S.top()->cap -= bneck;
            S.top()->rev->cap += bneck;
            S.pop();
        }

        return bneck;
    }

    int max_flow(int source, int sink) {
        int flow = 0;
        while (true) {
            int f = augment(source, sink);
            if (f == 0) {
                break;
            }

            flow += f;
        }

        return flow;
    }
};


int grid[320][320];

int main(){
    flow_network fn(MAX);

    int r,c; scanf("%d %d",&r,&c);
    int tc = 1;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&grid[i][j]);

            // printf("%d\t",grid[i][j]);
        }
        // printf("\n");
    }
    int x,y; scanf("%d %d",&x,&y);

    int castleIndex = x*c+y;
   
    int totalGrid = r*c;
    int s = totalGrid*2;
    int t = totalGrid*2+1;

    fn.add_edge(s,castleIndex+totalGrid,grid[x][y]);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int currIndex = i*c+j;
            fn.add_edge(currIndex,currIndex+totalGrid,grid[i][j]);
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int currIndex = i*c+j;

            if (j+1 < c)   fn.add_edge(currIndex+totalGrid,currIndex+1,INF);
            else  fn.add_edge(currIndex+totalGrid,t,INF);

            if (j-1 >= 0)  fn.add_edge(currIndex+totalGrid,currIndex-1,INF);
            else  fn.add_edge(currIndex+totalGrid,t,INF);

            if (i+1 < r) fn.add_edge(currIndex+totalGrid,currIndex+c,INF);
            else  fn.add_edge(currIndex+totalGrid,t,INF);

            if (i-1 >= 0) fn.add_edge(currIndex+totalGrid,currIndex-c,INF);
            else  fn.add_edge(currIndex+totalGrid,t,INF);
        }
    }

    printf("%d\n",fn.max_flow(s,t));

    return 0;
}
