#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e5;
vector<vector<ll>> memo(N + 11, vector<ll>(2, -1));
ll dp(vector<pair<int, int>> &space, int i, bool c) {
    int n = space.size();
    if (i >= n) return 0;
    auto &ret = memo[i][c];
    if (ret != -1) return ret;
    auto [L, R] = space[i];
    if (c) {
        // cout << "CHOICE LEFT i " << i << " L " << L << " R " << R << " c " << c << endl;
        ret = max({ret, L + dp(space, i + 1, 1), R + dp(space, i + 1, 0)});
        // cout << "ret " << ret << endl;
        return ret;
    } else {
        // cout << "CHOICE RIGHT i " << i << " L " << L << " R " << R << " c " << c << endl;
        ret = max({ret, R + dp(space, i + 1, 0)});
        // cout << "ret " << ret << endl;
        return ret;
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                int lcnt = 0, rcnt = 0;
                for (int j = i - 1; (s[j] == 'A') && (j >= 0); j--)  {
                    lcnt++;
                }
                for (int j = i + 1; (s[j] == 'A') && (j < n); j++)  {
                    rcnt++;
                }
                v.push_back({lcnt, rcnt});
            }
        }

        for (auto &i : memo) fill(i.begin(), i.end(), -1);
        /*
        for (auto [l, r] : v) {
            cout << "(" << l << ", " << r << ") ";
        }
        */
        cout << dp(v, 0, 'L') << endl;
    }
    return 0;
}
