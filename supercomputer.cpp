// https://open.kattis.com/problems/supercomputer

#include <bits/stdc++.h>
using namespace std;

int LSOne(int a) {
	return a & (~a + 1);
}

class FenwickTree {
   private:
	vector<int> ft;

   public:
	FenwickTree(int n) {
		ft.assign(n+1, 0);
	}
	int rsq(int n) {
		int sum = 0;
		while (n > 0) {
			sum += ft[n];
			n = n - LSOne(n);
		}
		return sum;
	}
	int rsq(int n, int m) {
		if (n <= 1) return rsq(m);
		return rsq(m) - rsq(n - 1);
	}
	int update(int i, int v) {
		int k = i;
		for (; k < ft.size(); k += LSOne(k)) {
			ft[k] += v;
		}
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	FenwickTree fenwick(n);
	while (k--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'F') {
			int idx;
			cin >> idx;
			int currValue = fenwick.rsq(idx, idx);
			if (currValue == 1)
				fenwick.update(idx, -1);
			else if (currValue == 0)
				fenwick.update(idx, 1);
		} else if (cmd == 'C') {
			int l, r;
			cin >> l >> r;
			int freq = fenwick.rsq(l, r);
			cout << freq << endl;
		}
	}
	return 0;
}
