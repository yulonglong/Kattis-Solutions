// https://open.kattis.com/problems/averageseasy

#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

double cs[MAX];
double econ[MAX];

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int nCs, nE; cin >> nCs >> nE;
		for (int i=0;i<nCs;i++) cin >> cs[i];
		for (int i=0;i<nE;i++) cin >> econ[i];

		double aveCs = 0.0;
		double aveEcon = 0.0;
		int idxCs = nCs-1;
		int idxEcon = nE-1;
		
		for (int i=0;i<nCs;i++) aveCs += (double) cs[i];
		aveCs = aveCs / (double) nCs;
		for (int i=0;i<nE;i++) aveEcon += (double) econ[i];
		aveEcon = aveEcon / (double) nE;

		int count = 0;
		for (int i=0;i<nCs;i++) {
			if ((double) cs[i] < aveCs && (double) cs[i] > aveEcon) {
				count++;
			}
		}

		cout << count << endl;
	}
	return 0;
}

