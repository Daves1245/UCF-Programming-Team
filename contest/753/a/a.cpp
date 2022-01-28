/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 1;
    while (m * (m + 1) / 2 < n) {
        m++;
    }

    if (m * (m + 1) / 2 == n) {
        cout << m << endl;
    } else {
        cout << m - 1 << endl;
    }

    for (int i = 1; i <= m; i++) {
        if (i == m * (m + 1) / 2 - n) continue;
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

