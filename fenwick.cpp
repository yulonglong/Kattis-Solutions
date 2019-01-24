// https://open.kattis.com/problems/fenwick

#include <bits/stdc++.h>
using namespace std;

long long LSOne(long long i) { return i & (~i+1); }

class Fenwick {
    private:
        vector<long long> ft;
    public:
        Fenwick(long long N) {
            ft.assign(N+2,0);
        }
        void update(long long idx, long long val) {
            for (;idx<ft.size();idx+=LSOne(idx)) {
                ft[idx] += val;
            }
        }
        long long rsq(long long idx) {
            if (idx <= 0) return 0;
            long long sum = 0;
            while (idx > 0) {
                sum += ft[idx];
                idx -= LSOne(idx);
            }
            return sum;
        }
};

int main() {
    long long n, q; scanf("%lld %lld\n", &n, &q);
    Fenwick f(n);
    while (q--) {
        char op; long long a,b;
        scanf("%c ", &op);
        if (op == '+') {
            scanf("%lld %lld\n", &a, &b);
            f.update(a+1,b);
        }
        else {
            scanf("%lld\n", &a);
            printf("%lld\n", f.rsq(a));
        }
    }
    return 0;
}