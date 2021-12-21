/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;


constexpr int N = 100 + 10;
constexpr int M = 100 + 10;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;

        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }

        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        int sr = 0, maxr = 0;
        int sb = 0, maxb = 0;

        for (int i = 0; i < n; i++) {
            sr += r[i];
            maxr = max(maxr, sr);
        }

        for (int i = 0; i < m; i++) {
            sb += b[i];
            maxb = max(maxb, sb);
        }

        cout << maxr + maxb << endl;
    }

    return 0;
}

