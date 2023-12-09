#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> a;
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1] - v[i] > 1) a.push_back(v[i + 1] - v[i]);
        }
        if (a.size() == 0) {
            cout << "YES" << endl;
            continue;
        }
        if ((a.size() == 1) && (a[0] <= 3)) {
            cout << "YES" << endl;
            continue;
        }
        if ((a.size() == 2) && (a[0] == 2) && (a[1] == 2)) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
