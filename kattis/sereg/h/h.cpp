/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, w, h; cin >> l >> w >> h;
    cout << 4 * max(max(h * w, h * (l - w)), max((l - h) * (l - w), (l - h) * w)) << endl;
    return 0;
}

