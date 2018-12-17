// https://open.kattis.com/problems/flexible

#include <iostream>
#include <set>
using namespace std;

int partition[101];

int main() {
	int w, p;
	cin >> w >> p;
	partition[0] = 0;
	for(int i=1;i<=p;i++){
		cin >> partition[i];
	}
	partition[p+1] = w;

	set<int> answer;

	for(int i=0;i<=p+1;i++) {
		for(int j=i+1;j<=p+1;j++) {
			answer.insert(partition[j]-partition[i]);
		}
	}

	set<int>::iterator it;

	for(it = answer.begin();it != answer.end(); it++ ){
		if ( it == answer.begin()) cout << *it;
		else cout << " " << *it;
	}
	cout << endl;


	return 0;
}
