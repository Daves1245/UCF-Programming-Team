#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<pair<int, int>> a(n), b(n), c(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }

        for (int i = 0; i < n; i++) {
            cin >> c[i].first;
            c[i].second = i;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int mx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    auto [f, fi] = a[n - 1 - i];
                    auto [s, si] = b[n - 1 - j];
                    auto [t, ti] = c[n - 1 - k];
                    if ((fi != si) && (si != ti) && (ti != fi)) {
                        mx = max(mx, f + s + t); 
                    }
                }
            }
        }

        cout << mx << endl;
    }

    return 0;
}
