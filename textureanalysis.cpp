// https://open.kattis.com/problems/textureanalysis

#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	int tc = 1;
	while (getline(cin, line) && line != "END") {
		int idx = 0;
		int diff = -1;
		bool even = true;
		for (int i = 1; i < line.length(); i++) {
			if (line[i] == '*')	{
				if (diff == -1)	{
					diff = i - idx;
				}
				else {
					if ((i - idx) != diff) {
						even = false;
					}
				}
				idx = i;
			}
		}
		cout << tc++ << " ";
		if (even)
			cout << "EVEN" << endl;
		else
			cout << "NOT EVEN" << endl;
	}
	return 0;
}
