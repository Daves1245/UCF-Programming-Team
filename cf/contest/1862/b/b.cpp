#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> ans;
        ans.push_back(v[0]);
        for (int i = 1; i < n; i++) {
            ans.push_back(v[i]);
            if (v[i] < v[i - 1]) {
                ans.push_back(v[i]);
            }
        }
        cout << ans.size() << endl;
        for (auto i : ans) cout << i << " "; cout << endl;
    }
    return 0;
}
