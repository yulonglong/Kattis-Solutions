// https://open.kattis.com/problems/builddeps

#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

vector<int> adjList[MAX];
unordered_map<string, int> dt;
unordered_map<string, int>::iterator iter;
string reverseMap[MAX];
bool visited[MAX];

int idx = 0;
int getIdx(string dest) {
	int destIdx = -1;
	iter = dt.find(dest);
	if (iter == dt.end()) {
		dt.insert(make_pair(dest, idx));
		reverseMap[idx] = dest;
		destIdx = idx++;
	} else {
		destIdx = iter->second;
	}
	return destIdx;
}

void dfs(int x, vector<int>& ans) {
	visited[x] = true;
	for (int dest : adjList[x]) {
		if (!visited[dest]) {
			dfs(dest, ans);
		}
	}
	ans.push_back(x);
}

int main() {
	string line;
	getline(cin, line);
	int n = atoi(line.c_str());
	while (n--) {
		getline(cin, line);
		istringstream istream(line);
		string dest;
		istream >> dest;
		dest = dest.substr(0, dest.length() - 1);
		int destIdx = getIdx(dest);

		string token;
		while (istream >> token) {
			int tokenIdx = getIdx(token);
			adjList[tokenIdx].push_back(destIdx);
		}
	}
	string start;
	getline(cin, start);
	int startIdx = getIdx(start);
	memset(visited, false, sizeof(visited));
	
	vector<int> answer; // to keep track of the answers
	dfs(startIdx, answer);
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << reverseMap[answer[i]] << endl;
	}
	return 0;
}
