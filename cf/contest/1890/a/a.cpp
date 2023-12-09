#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> s;
        map<int, int> f;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
            f[x]++;
        }

        bool b = s.size() <= 2;
        for (auto [k, v] : f) {
            b &= v >= n / 2;
        }

        cout << (b ? "Yes" : "No") << endl;
    }

    return 0;
}
