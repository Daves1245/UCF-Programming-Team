#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if (k == 0) {
            cout << "YES" << endl;
            continue;
        }

        bool f = 2 * k + 1 <= n;
        for (int i = 0; i < k; i++) {
            f &= s[i] == s[n - 1 - i];
        }

        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
