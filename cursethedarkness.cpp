// https://open.kattis.com/problems/cursethedarkness

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

double euclideanDistance(double x1, double y1, double x2, double y2) {
    double ans = ((y2 - y1) * (y2 - y1)) + ((x2 - x1) * (x2 - x1));
    return sqrt(ans);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        bool valid = false;
        double x, y;
        cin >> x >> y;
        int m;
        cin >> m;
        while (m--) {
            double x1, y1;
            cin >> x1 >> y1;
            double dist = euclideanDistance(x, y, x1, y1);
            if (8.0 - dist >= -EPS) {
                valid = true;
            }
        }
        if (valid)
            cout << "light a candle" << endl;
        else
            cout << "curse the darkness" << endl;
    }
    return 0;
}
