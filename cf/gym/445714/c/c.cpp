#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        char c; cin >> n >> c;
        string s; cin >> s;

        s += s;
        n += n;

        int best = 0;
        int cur = 0;
        bool f = false;
        for (int i = 0; i < n; i++) {
            f |= s[i] == c;
            cur += f;
            best = max(best, cur);
            if (s[i] == 'g') {
                f = false;
                cur = 0;
            }
        }

        cout << best - 1 << endl;
    }

    return 0;
}
