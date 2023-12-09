#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        vector<pair<char, int>> v;
        for (auto i : s) {
            if (!v.size() || (v.back().first != i)) v.push_back({i, 1});
            else v.back().second++;
        }
        int ans = 1e9;
        for (int i = 1; i < v.size() - 1; i++) {
            if (v[i - 1].first != v[i + 1].first) {
                ans = min(ans, v[i].second + 2);
            }
        }

        cout << (ans > n ? 0 : ans) << endl;
    }
    return 0;
}
