#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;

        auto good = [](string s) -> int {
            int ret = 1;
            for (int i = 0; i < s.size() - 1; i++) {
                ret &= s[i] != s[i + 1];
            }
            return ret;
        };

        if (good(s)) {
            cout << "Yes" << endl;
            continue;
        }

        bool f = good(t);

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) f &= (s[i] != t[0]) && (t[m - 1] != s[i + 1]);
        }

        cout << (f ? "Yes" : "No") << endl;
    }

    return 0;
}
