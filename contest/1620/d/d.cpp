#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int mv = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mv = min(mv, v[i] / 3);
        }

        int mc = INT_MAX;
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                int maxc = 0;
                for (int i = 0; i < n; i++) {
                    if ((v[i] - 1 * a - 2 * b) % 3 == 0) {
                        maxc = max(maxc, (v[i] - a - 2 * b) / 3);
                    }
                }
                mc = min(mc, maxc + a + b);
            }
        }
        cout << mc << endl;
    }
    return 0;
}

