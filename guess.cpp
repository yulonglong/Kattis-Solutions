// https://open.kattis.com/problems/guess

#include <bits/stdc++.h>
using namespace std;

int main() {
    string response = "";
    int lower = 1;
    int upper = 1000;
    int mid = (lower + upper) / 2;
    while (response != "correct") {
        if (response == "lower") {
            upper = mid-1;
        }
        else if (response == "higher") {
            lower = mid+1;
        }
        mid = (lower + upper) / 2;
        cout << mid << endl;
        cout << flush;
        cin >> response;
    }
    return 0;
}
