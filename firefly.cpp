// https://open.kattis.com/problems/firefly

#include <bits/stdc++.h>
using namespace std;
#define MAX 200500

int n, h;
int hBot[MAX];
int hTop[MAX];

int binarySearch(int currHeight, int height[]) {
    int lower = 0;
    int upper = n/2;
    while (lower < upper) {
        int mid = (lower + upper) / 2;
        if (height[mid] >= currHeight) upper = mid;
        else lower = mid+1;
    }
    return n/2-lower;
}

int getObstaclesDestroyed(int currHeight) {
    int bot = binarySearch(currHeight, hBot);
    int top = binarySearch(h - currHeight + 1, hTop);
    // cout << bot << " + " << top << endl;
    return bot + top;
}

void getMinimumObstacledDestroyed(int& numDestroyed, int& count) {
    int currMin = 2e9;
    count = 0;
    for (int height=1;height<=h;height++) {
        int currObsDestroyed = getObstaclesDestroyed(height);
        // cout << height << " : " << currObsDestroyed << endl;
        if (currMin > currObsDestroyed) {
            currMin = currObsDestroyed;
            count = 1;
        }
        else if (currMin == currObsDestroyed) count++;
    }
    numDestroyed = currMin;
}

int main() {
    scanf("%d %d\n", &n, &h);
    for (int i=0;i<n;i++){
        if (i%2 == 0) scanf("%d\n", &hBot[i/2]);
        else scanf("%d\n", &hTop[i/2]);
    }
    sort(hBot, hBot+(n/2));
    sort(hTop, hTop+(n/2)); 
    int bestNumDestroyed, count;
    getMinimumObstacledDestroyed(bestNumDestroyed, count);
    cout << bestNumDestroyed << " " << count << endl;
    return 0;
}
