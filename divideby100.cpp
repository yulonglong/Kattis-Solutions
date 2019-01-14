// https://open.kattis.com/problems/divideby100

#include <bits/stdc++.h>
using namespace std;

int main() {
	string n, m;
	cin >> n >> m;
	int nLen = n.length();
	int mLen = m.length() - 1;
	ostringstream ostream;
	if (mLen >= nLen) {
		int diff = mLen - nLen;
		ostream << "0.";
		for (int i = 0; i < diff; i++) {
			ostream << "0";
		}
		for (int i = 0; i < nLen; i++) {
			ostream << n[i];
		}
	} else {
		for (int i = 0; i < nLen; i++) {
			if (nLen - i == mLen) {
				ostream << ".";
			}
			ostream << n[i];
		}
	}
	string currAns = ostream.str();
	int maxIndex = currAns.length();
	for (maxIndex = currAns.length()-1;maxIndex>=0;maxIndex--) {
		if (currAns[maxIndex] == '0') continue;
		else if (currAns[maxIndex] == '.') break;
		else {
			maxIndex++; break;
		}
	}
	cout << currAns.substr(0,maxIndex) << endl;
	return 0;
}
