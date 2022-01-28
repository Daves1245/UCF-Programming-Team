/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    int m = INT_MAX, mi = 0;
    for (int i = k; i <= n; i++) {
        if (v[i] - v[i - k] < m) {
            m = v[i] - v[i - k];
            mi = i - k;
        }
    }
    cout << mi + 1 << endl;
    return 0;
}

