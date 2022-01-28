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
    while (n--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << ((k >= (r - l) / 2) ? "YES" : "NO") << endl;
    }
    return 0;
}

