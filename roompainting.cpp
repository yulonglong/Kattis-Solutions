// https://open.kattis.com/problems/roompainting

#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

int paint[MAX];

int binarySearch(int n, int needAmt) {
    int lower = 0;
    int upper = n-1;
    while (lower < upper) {
        int mid = (lower + upper) / 2;
        if (paint[mid] < needAmt) lower = mid+1;
        else upper = mid;
    }
    return paint[lower];
}

int main() {
    int n, m; scanf("%d %d\n", &n, &m);
    for (int i=0;i<n;i++){
        scanf("%d\n", &paint[i]);
    }
    sort(paint, paint+n);
    unsigned long long totalWasted = 0;
    for (int i=0;i<m;i++){
        int needAmt;
        scanf("%d\n", &needAmt);
        long long minCanSize = binarySearch(n, needAmt);
        totalWasted += (minCanSize - needAmt);
    }
    printf("%lld\n", totalWasted);
    return 0;
}