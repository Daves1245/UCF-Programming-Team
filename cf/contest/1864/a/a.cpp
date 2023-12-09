#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int x, y, n; cin >> x >> y >> n;
        vector<int> ans(n);
        ans[0] = y;
        int d = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] - d;
            d++;
        }
        if (ans[n - 1] < x) {
            cout << - 1 << endl;
        } else {
            ans[n - 1] = x;
            reverse(ans.begin(), ans.end());
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
