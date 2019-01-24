// https://open.kattis.com/problems/aboveaverage

#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int grades[MAX];
        double total = 0.0;
        for (int i=0;i<n;i++){
            cin >> grades[i];
            total += grades[i];
        }
        double ave = total / (double)n;
        int aboveAverage = 0;
        for (int i=0;i<n;i++){
            if ((double)grades[i] > ave) {
                aboveAverage++;
            }
        }

        double answer = (double)aboveAverage * 100.0 / (double)n;
        printf("%.3f%%\n",answer);
    }
    return 0;
}