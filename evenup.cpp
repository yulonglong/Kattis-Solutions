// https://open.kattis.com/problems/evenup

#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int num[MAX];

int main() {
	int n; cin>> n;
	for (int i=0;i<n;i++) cin >> num[i];

	stack<int> st;
	for (int i=0;i<n;i++) {
		if (!st.empty() && num[i] % 2 == st.top() % 2) st.pop();
		else st.push(num[i]);
	}
	cout << st.size() << endl;
	return 0;
}
