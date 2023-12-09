#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int ec = 0, oc = 0;
        for (auto i : v) ((i % 2) ? oc : ec)++;
        if ((ec == n) || (oc == n)) {
            cout << "YES" << endl;
            continue;
        }
        bool good = true;
        int mo = *max_element(v.begin(), v.end());
        if (oc) {
            for (int i = 0; i < n; i++) {
                if (v[i] < mo && (v[i] % 2)) mo = v[i];
            }
            for (int i = 0; i < n; i++) {
                if ((v[i] % 2) == 0) good &= mo < v[i];
            }
        }

        cout << (good ? "YES" : "NO") << endl;
    }

    return 0;
}
