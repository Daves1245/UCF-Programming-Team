#include <bits/stdc++.h>

using namespace std;

int n, m;

bool dp(int x, int y, int k) {
    if (k < 0) return false;
    if (k == 0 && x == n && y == m) return true;
    return dp(x + 1, y, k - y) || dp(x, y + 1, k - x);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k;
        cin >> n >> m >> k;
        if (dp(1, 1, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

