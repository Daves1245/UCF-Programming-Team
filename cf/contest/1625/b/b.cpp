#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, int> m;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int ans = -1;
        int i = 0;
        for (auto x : v) {
            auto it = m.find(x);
            if (it != m.end()) ans = max(ans, n - (i - it->second));
            m[x] = i++;
        }
        cout << ans << endl;
    }
    return 0;
}
