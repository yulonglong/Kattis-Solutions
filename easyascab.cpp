// https://open.kattis.com/problems/easyascab

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define MAX 27

class UnionFind {
   private:
    vector<int> rank, p;

   public:
    UnionFind(int n) {
        p.assign(n, 0);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int findSet(int i) {
        if (p[i] == i)
            return i;
        else
            return p[i] = findSet(p[i]);
    }
    int unionSet(int i, int j) {
        int x = findSet(i);
        int y = findSet(j);
        if (x != y) {
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

vector<vi> adjList;
set<int> recursionStack;
bool visited[MAX];
vector<int> answerStack;
bool isCycle = false;

void dfs(int x, bool forward) {
    // cout << "inside "<< x << endl;
    if (forward) {
        for (int i = 0; i < adjList[x].size(); i++) {
            int y = adjList[x][i];
            // cout << "Forward dfs at " << x << " -> " << y << endl;

            if (recursionStack.find(y) == recursionStack.end()) {
                if (!visited[y]) {
                    // cout << "Forward dfs at " << x << " -> " << y << endl;
                    visited[y] = true;
                    recursionStack.insert(y);
                    dfs(y, forward);
                }
            } else {
                // cout << "cycle" << endl;
                isCycle = true;
                return;
            }
        }
    } else {
        for (int i = adjList[x].size() - 1; i >= 0; i--) {
            int y = adjList[x][i];
            // cout << "Back dfs at " << x << " -> " << y << endl;
            if (recursionStack.find(y) == recursionStack.end()) {
                if (!visited[y]) {
                    // cout << "Backawrd dfs at " << x << " -> " << y << endl;
                    visited[y] = true;
                    recursionStack.insert(y);
                    dfs(y, forward);
                }
            } else {
                // cout << "cycle" << endl;
                isCycle = true;
                return;
            }
        }
    }
    // cout << "Completed dfs at " << x << endl;
    recursionStack.erase(x);
    answerStack.push_back(x);
    return;
}

int main() {
    char L;
    int N;
    cin >> L >> N;
    int numVertex = L - 'a' + 1;
    adjList.assign(numVertex, vi());
    UnionFind ufds(numVertex);

    string prev;
    cin >> prev;
    string curr;
    for (int i = 1; i < N; i++) {
        cin >> curr;
        // cout << prev << ":" << curr << endl;
        int minLen = min(prev.length(), curr.length());
        for (int j = 0; j < minLen; j++) {
            if (prev[j] == curr[j])
                continue;
            else {
                int lowerChar = prev[j] - 'a';
                int higherChar = curr[j] - 'a';
                // cout << lowerChar << " -> " << higherChar << endl;
                adjList[lowerChar].push_back(higherChar);
                ufds.unionSet(lowerChar, higherChar);
                break;
            }
        }
        prev = curr;
    }

    // dfs forward time
    answerStack.clear();
    recursionStack.clear();
    memset(visited, 0, sizeof(visited));
    isCycle = false;
    for (int i = 0; i < numVertex; i++) {
        if (!visited[i]) {
            visited[i] = true;
            recursionStack.insert(i);
            dfs(i, true);
            if (isCycle) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    string firstAnswer = "";
    for (int i = answerStack.size() - 1; i >= 0; i--) {
        firstAnswer += (char)(answerStack[i] + 'a');
    }
    // cout << "firstAnswer : " << firstAnswer << endl;
    // cout << "========================" << endl;

    // dfs reverse time
    answerStack.clear();
    recursionStack.clear();
    memset(visited, 0, sizeof(visited));
    isCycle = false;
    for (int i = 0; i < numVertex; i++) {
        if (!visited[i]) {
            visited[i] = true;
            recursionStack.insert(i);
            dfs(i, false);
            if (isCycle) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    string secondAnswer = "";
    for (int i = answerStack.size() - 1; i >= 0; i--) {
        secondAnswer += (char)(answerStack[i] + 'a');
    }
    // cout << "secondAnswer : " << secondAnswer << endl;

    if (firstAnswer != secondAnswer) {
        cout << "AMBIGUOUS" << endl;
        return 0;
    }

    int firstParent = ufds.findSet(0);
    for (int i = 1; i < numVertex; i++) {
        int currParent = ufds.findSet(i);
        if (currParent != firstParent) {
            cout << "AMBIGUOUS" << endl;
            return 0;
        }
    }
    cout << firstAnswer << endl;

    return 0;
}
