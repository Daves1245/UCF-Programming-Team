#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mex = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == mex) mex++;
        }

        cout << mex << endl;
        cout.flush();

        for (int i = 0; i < 2 * n; i++) {
            int y; cin >> y;
            if (y == -1) break;
            if (y == -2) return 0;
            else cout << y << endl;
            cout.flush();
        }
    }
    return 0;
}
