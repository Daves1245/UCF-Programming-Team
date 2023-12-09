#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        int oc = 0, ec;
        vector<int> v(n); for (auto &i : v) cin >> i, oc += i % 2;
        ec = n - oc;
        if (!oc) {
            cout << "No" << endl;
            continue;
        }
        bool f = 0;
        for (int i = 1; i <= min(oc, x); i += 2) {
            f |= ec >= x - i;
        }
        cout << (f ? "Yes" : "No") << endl;
    }
    return 0;
}
