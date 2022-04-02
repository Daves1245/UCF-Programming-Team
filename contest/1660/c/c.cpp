#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string a; cin >> a;
        if (a.size() == 1) {
            cout << 1 << endl;
            continue;
        }

        int k = 1;
        vector<long long> li(26, INT_MAX);
        vector<long long> ps(a.size(), INT_MAX);
        for (int i = 0; i < a.size(); i++) {
            int c = a[i] - 'a';
            if (li[c] != INT_MAX)
                ps[li[c]] = i - li[c] - 1;
            else
                ps[i] = INT_MAX;
            li[c] = i;
        }

        for (int i = 0; i < a.size(); i++) {
            cout << ps[i] << " ";
        }
        cout << endl;

        int ans = 0;
        int i = 0;
        while (i < a.size()) {
            if (ps[i] == INT_MAX) {
                ans++;
                i++;
                continue;
            }
            if (ps[i] < ps[i + 1]) {
                i += ps[i] + 1;
                ans += ps[i];
            } else {
                i += ps[i + 1] + 1;
                ans += ps[i + 1];
            }
        }

        if ((a.size() - ans) % 2) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

