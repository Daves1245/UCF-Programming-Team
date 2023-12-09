#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int f = 0;
        int cnt = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cnt += s[i] == '.';
            if (s[i] == '.') {
                cur++;
            } else {
                cur = 0;
            }
            if (cur >= 3) {
                f = 1;
            }
        }
        if (f) {
            cout << 2 << endl;
        } else {
            cout << cnt << endl;
        }
    }

    return 0;
}
