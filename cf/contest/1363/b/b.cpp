#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        vector<int> p(n + 1, 0);
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + (s[i] == '1');
        }

        int mn = INT_MAX;
        for (int i = 1; i <= s.size(); i++) {
            mn = min({
                    mn,
                    i - p[i] + p[n] - p[i],
                    p[i] + (n - i) - (p[n] - p[i])
                    });
        }

        cout << mn << endl;
    }

    return 0;
}
