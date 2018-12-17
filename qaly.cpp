// https://open.kattis.com/problems/qaly

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double ans = 0;
    while (n--) {
        double a, b;
        cin >> a >> b;
        ans += (a * b);
    }
    printf("%.3f\n", ans);
    return 0;
}
