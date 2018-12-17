// https://open.kattis.com/problems/equalsumseasy

#include <bits/stdc++.h>
#define found 9999
#define notfound 9999
using namespace std;

int num[20];
bool pos[20];
bool neg[20];

bool isPossible(int index, int current) {
	if (current>0) {
		for(int i=index;i<20;i++){
			current -= num[index];
		}
		if (current > 0) return false;
	}
	if (current<0) {
		for(int i=index;i<20;i++){
			current += num[index];
		}
		if (current < 0 ) return false;
	}
	return true;
}

bool findSum(int index, int current){
	// for(int i=0;i<20;i++){
	// 	if(pos[i]) cout << "1";
	// 	else cout << "0";
	// }
	// cout << endl;
	// for(int i=0;i<20;i++){
	// 	if(neg[i]) cout << "1";
	// 	else cout << "0";
	// }
	// cout << endl;
	// cout << index << " - " << current << endl;

	if ((current == 0) && (index > 0)) {
		for(int i=0;i<20;i++){
			if(pos[i]) cout << num[i] << " ";
		}
		cout << endl;
		for(int i=0;i<20;i++){
			if(neg[i]) cout << num[i] << " ";
		}
		cout << endl;
		// cout <<"true" << endl;
		// cout << index << " - " << current << endl;
		return true;
	}
	if ((index >= 20) && (current != 0)) return false;
	//if (!isPossible(index,current)) return false;

	pos[index] = true;
	if (findSum(index+1,current+num[index])) {
		return true;
	}
	pos[index] = false;

	if (index > 0) {
		if (findSum(index+1,current)) {
			return true;
		}
	}

	neg[index] = true;
	if (findSum(index+1,current-num[index])) {
		return true;
	}
	neg[index] = false;

	return false;
}


int main() {
	int t;
	cin >> t;
	for (int z=1;z<=t;z++) {
		memset(pos,false,sizeof(pos));
		memset(neg,false,sizeof(neg));
		int n; cin >> n;
		for(int i=0;i<n;i++){
			cin >> num[i];
		}
		cout << "Case #" << z << ":" << endl;
		if (!findSum(0,0)) {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
