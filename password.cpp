// https://open.kattis.com/problems/password

#include <bits/stdc++.h>
using namespace std;
#define MAX 501

double prob[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string password;
        cin >> password >> prob[i];
    }
    double answer = 0;
    sort(prob, prob + n);
    int count = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer += count * prob[i];
        count++;
    }
    printf("%.4f\n", answer);
    return 0;
}
