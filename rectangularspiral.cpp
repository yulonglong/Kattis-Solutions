// https://open.kattis.com/problems/rectangularspiral

#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int k;
        cin >> k;
        int x, y;
        cin >> x >> y;
        cout << k << " ";

        if (x == y && x <= 3)
            cout << "NO PATH" << endl;
        else if (x < y)
            cout << "2 " << x << " " << y << endl;
        else {
            int l, m, r;
            m = x + 2;
            r = m + 1;
            int z = x - y + 3;
            l = z + 2;
            if (3 < l && l < m && m < r) {
                cout << "6 1 2 3 " << l << " " << m << " " << r << endl;
            } else {
                cout << "NO PATH" << endl;
            }
        }
    }
    return 0;
}
