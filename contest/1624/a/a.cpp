/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int ma = 0;
        int mi = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ma = max(ma, v[i]);
            mi = min(mi, v[i]);
        }
        cout << ma - mi << endl;
    }
    return 0;
}

