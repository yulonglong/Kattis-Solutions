// https://open.kattis.com/problems/ladice

#include <bits/stdc++.h>
using namespace std;
#define MAX 300100

class UnionFind {
    private:
        vector<int> p, rank;
        vector<int> size, used;
    public:
        UnionFind(int N) {
            size.assign(N,1);
            used.assign(N,0);
            p.assign(N,0);
            rank.assign(N,0);
            for (int i=0;i<N;i++){
                p[i] = i;
            }
        }
        int findParent(int i) {
            if (i == p[i]) return i;
            else return p[i] = findParent(p[i]);
        }
        bool unionSet(int i, int j) {
            int x = findParent(i);
            int y = findParent(j);
            if (x == y) return false;
            if (rank[x] > rank[y]) {
                p[y] = x;
                size[x] += size[y];
                used[x] += used[y];
            }
            else {
                p[x] = y;
                size[y] += size[x];
                used[y] += used[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
        bool incrementUsed(int i) {
            int x = findParent(i);
            used[x]++;
            if (used[x] <= size[x]) return true;
            else {
                used[x]--;
                return false;
            }
        }
};

int main() {
    UnionFind ufds(MAX);
    int n,l; cin >> n >> l;
    for (int i=0;i<n;i++){
        int a, b; cin >> a >> b;
        ufds.unionSet(a,b);
        if (ufds.incrementUsed(a)) {
            cout << "LADICA" << endl;
        }
        else {
            cout << "SMECE" << endl;
        }
    }
    return 0;
}
