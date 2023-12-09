#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size(), m; cin >> m;
        string l, r; cin >> l >> r;

        /*
        cout << "s " << s << endl;
        cout << "l " << l << endl;
        cout << "r " << r << endl;
        cout << "n " << n << endl;
        cout << "m " << m << endl;
        */

        // s[i]
        // p[j]

        int i = 0;
        for (int j = 0; j < m; j++) {
            int best = i;
            for (int d = l[j]; d <= r[j]; d++) {
                int k = i;
                while (k < n && s[k] != d) k++;
                best = max(best, k);
            }
            i = best + 1;
        }

        cout << (i > n ? "YES" : "NO") << endl;
        // cout << i << endl;
    }

    return 0;
}
