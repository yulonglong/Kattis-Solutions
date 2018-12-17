// https://open.kattis.com/problems/islands

#include <bits/stdc++.h>
using namespace std;
#define MAX 12

int main() {
	int tc;
	cin >> tc;
	int numbers[MAX];
	int islands[MAX];
	set<int> uniqueNum;
	set<int>::reverse_iterator rvIter;
	while (tc--) {
		memset(islands, 0, sizeof(islands));
		uniqueNum.clear();
		int k;
		cin >> k;
		for (int i = 0; i < MAX; i++) {
			cin >> numbers[i];
			uniqueNum.insert(numbers[i]);
		}
		int count = 0;
		
		int prevMark[MAX];
		int mark[MAX];
		memset(prevMark,0,sizeof(prevMark));
		for (rvIter = uniqueNum.rbegin(); rvIter != uniqueNum.rend(); rvIter++) {
			memset(mark,0,sizeof(mark));
			if (*rvIter == 0)
				break;
			for (int i = 0; i < MAX; i++) {
				if (numbers[i] == (*rvIter)) islands[i] = 1;
				if (i > 0) {
					if (islands[i] > islands[i-1]) mark[i] = 1;
					else if (islands[i] < islands[i-1]) mark[i] = -1;
				}
				// cout << islands[i];
			}
			// cout << endl;
			bool sameStart = false;
			bool pending = false;
			bool middleSame = true;
			for (int i = 0; i < MAX; i++) {
				// cout << mark[i];
				if (mark[i] == 1) {
					pending = true;
					middleSame = true;
					if (prevMark[i] == 1) sameStart = true;
				}
				else if (mark[i] == -1) {
					if (sameStart && middleSame && prevMark[i] == -1) {
						count--;
					}
					middleSame = false; pending = false; sameStart = false;
					count++;
				}
				else if (pending) {
					if (mark[i] != prevMark[i]) middleSame = false;
				}
				prevMark[i] = mark[i];
			}

			// cout << endl;
		}
		// int answer = 0;
		// for (int i: count) answer += i;
		cout << k << " " << count << endl;
	}
	return 0;
}
