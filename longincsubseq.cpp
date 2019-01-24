// https://open.kattis.com/problems/longincsubseq

#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

int num[MAX];
int p[MAX];
int idx[MAX];
int ans[MAX];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i=0;i<n;i++){
            scanf("%d", &num[i]);
        }
        for (int i=0;i<MAX;i++){
            ans[i] = 2e9;
            p[i] = -1;
        }
        int currMax = 0;

        // Perform LIS (nlogk) using binary search lower_bound
        for (int i=0;i<n;i++){
            // cout << num[i] << endl;
            int currIdx = lower_bound(ans,ans+n,num[i]) - ans;
            // cout << "IDX " << currIdx << endl;
            if (currMax < currIdx+1) {
                currMax = currIdx+1;
            }
            if (currIdx > 0) p[i] = idx[currIdx-1];
            ans[currIdx] = num[i];
            idx[currIdx] = i;
        }
        
        // Get the answers (indices) for the LIS
        vector<int> ansList;
        int curr = idx[currMax-1];
        while (curr != -1) {
            ansList.push_back(curr);
            curr = p[curr];
        }
        reverse(ansList.begin(), ansList.end());

        // Print the answer
        cout << currMax << endl;
        cout << ansList.front();
        for (int i=1;i<ansList.size(); i++) {
            cout << " " << ansList[i];
        }
        cout << endl;
    }
    return 0;
}
