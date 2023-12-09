#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;

        vector<tuple<int, int, int>> ans;
        for (int i = 0; i < n; i++) {
            int mn = INT_MAX, mi = -1;
            for (int j = i + 1; j < n; j++) {
                if (v[j] < mn) {
                    mn = v[j];
                    mi = j;
                }
            }

            if ((mi != -1) && (v[mi] < v[i])) {
                ans.push_back({i + 1, mi + 1, mi - i});
                rotate(v.begin() + i, v.begin() + mi, v.begin() + mi + 1);
                /*
                for (auto i : v) {
                    cout << i << " ";
                }
                cout << endl;
                */
            }
        }
        cout << ans.size() << endl;
        for (auto [a, b, c] : ans) {
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}
