// https://open.kattis.com/problems/prerequisites

#include <bits/stdc++.h>
using namespace std;

set<string> subjectTaken;

int main() {
	int k, m;
	while (cin >> k && k != 0) {
		cin >> m;
		subjectTaken.clear();
		for (int i = 0; i < k; i++) {
			string subject;
			cin >> subject;
			subjectTaken.insert(subject);
		}
		bool pass = true;

		for (int i = 0; i < m; i++) {
			int c, r;
			cin >> c >> r;
			int currPass = 0;
			for (int j = 0; j < c; j++) {
				string subject;
				cin >> subject;
				if (pass && subjectTaken.find(subject) != subjectTaken.end()) {
					currPass++;
				}
			}
			if (currPass < r)
				pass = false;
		}
		if (pass)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
