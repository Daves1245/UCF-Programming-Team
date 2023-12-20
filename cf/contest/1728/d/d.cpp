#include <bits/stdc++.h>
using namespace std;
using ll = int;
using vll = vector<ll>;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        vector<vector<vll>> memo(n + 1, vector<vll>(n + 1, vll(26, -1)));
        auto dp = [&](auto &&dp, int l, int r, char c) -> int {
            if (r - l == 1) return s[l] != s[r];
            c -= 'a';
            auto &ret = memo[l][r][c]; 
            c += 'a';

            if (ret != -1) {
                return ret;
            }

            if ((r - l + 1) % 2 == 1) { // Bob
                ret = 1LL;
                if (s[l] == c) {
                    ret = min(ret, dp(dp, l + 1, r, s[l]));
                }
                if (s[r] == c) {
                    ret = min(ret, dp(dp, l, r - 1, s[r]));
                }
                return ret;
            } else { // Alice
                ret = max(dp(dp, l + 1, r, s[l]), dp(dp, l, r - 1, s[r]));
                return ret;
            }
        };

        cout << (dp(dp, 0, n - 1, 'a') ? "Alice" : "Draw") << endl;
    }

    return 0;
}
