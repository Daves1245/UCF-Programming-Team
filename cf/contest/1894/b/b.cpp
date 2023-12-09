#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> ans(n, 1);
        auto cp = v;

        vector<int> freq(101, 0);
        for (auto i : v) freq[i]++;
        int cnt = 0;
        for (auto i : freq) cnt += i >= 2;
        if (cnt < 2) {
            cout << -1 << endl;
            continue;
        }
        int one = -1, two = -1;
        bool one_done = 0, two_done = 0;

        for (int i = 0; i < n; i++) {
            if (freq[v[i]] >= 2) {
                if ((one == -1) || (v[i] == one)) {
                    one = v[i];
                    ans[i] = 1;
                } else if ((two == -1) || (v[i] == two)) {
                    two = v[i];
                    ans[i] = 2;
                }
            } else {
                ans[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (v[i] == one) {
                if (one_done) continue;
                else ans[i] = 2, one_done = 1;
            }
            if (v[i] == two) {
                if (two_done) continue;
                else ans[i] = 3, two_done = 1;
            }
        }

        // cout << "v "; for (auto i : v) cout << i << " "; cout << endl; cout << "a ";
        for (int i : ans) cout << i << " "; cout << endl;
    }

    return 0;
}
