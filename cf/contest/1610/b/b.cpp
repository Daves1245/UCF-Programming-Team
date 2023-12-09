#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;

        auto kal = [](vector<int> &v, int i) -> bool {
            vector<int> ret;
            for (auto j : v) if (i != j) ret.push_back(j);
            vector<int> cp = ret;
            reverse(cp.begin(), cp.end());
            return ret == cp;
        };
        bool f = 0;
        bool g = 1;
        for (int i = 0; !f && g && i < n; i++) {
            if (v[i] != v[n - 1 - i]) {
                if (kal(v, v[i]) || kal(v, v[n - 1 - i])) {
                    f = 1;
                } else {
                    g = 0;
                }
            }
        }

        cout << (f || g ? "YES" : "NO") << endl;
    }
    return 0;
}
