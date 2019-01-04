// https://open.kattis.com/problems/bst

#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
typedef unsigned long long ull;

class Node {
   public:
	int pl, pr; // parent left, parent right
	int val; // current Node value
	bool l, r; // has left child, has right child
	ull h; // current node height
	Node() {}
	Node(int val, ull h) {
		l = false;
		r = false;
		this->pl = -INF;
		this->pr = INF;
		this->val = val;
		this->h = h;
	}
};

typedef pair<int,Node> ii;
map<int,Node> s;
map<int,Node>::iterator it;

int main() {
	ull totalH = 0;
	int n; cin >> n;
	// First element, insert first
	int num; cin >> num;
	// cout << "Inserted " << num << endl;
	s.insert(ii(num,Node(num,0)));
	cout << "0" << endl;
	for (int i = 1; i < n; i++) {
		cin >> num;
		// cout << "Inserting " << num << endl;
		// Try to insert as left child first
		it = s.upper_bound(num);
		if (it != s.end() && num > it->second.pl && it->second.l == false) {
			// cout << "Insert " << num  << " on the left of " << it->second.val << " || height: " << it->second.h + 1 << endl;
			it->second.l = true;
			Node newNode(num, it->second.h + 1);
			newNode.pl = it->second.pl;
			newNode.pr = it->second.val;
			totalH += it->second.h + 1;
			if (it->second.r) s.erase(it);
			s.insert(ii(num,newNode));
		// if left child not possible, then try to insert as right child
		} else if (it != s.begin()) {
			it--;
			if (it != s.end() && num < it->second.pr && it->second.r == false) {
				// cout << "Insert " << num  << " on the right of " << it->second.val << " || height: " << it->second.h + 1 << endl;
				it->second.r = true;
				Node newNode(num, it->second.h + 1);
				newNode.pl = it->second.val;
				newNode.pr = it->second.pr;
				totalH += it->second.h + 1;
				if (it->second.l) s.erase(it);
				s.insert(ii(num,newNode));
			}
		}
		cout << totalH << endl;
	}
	return 0;
}
