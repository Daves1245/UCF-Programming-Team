#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int cnt = count(s.begin(), s.end(), 'B');
        if (cnt == k) {
            cout << 0 << endl;
            continue;
        }

        cout << 1 << endl;
        if (cnt < k) {
            int a = 0;
            int f = 0;
            for (int i = 0; !f && i < n; i++) {
                a += s[i] == 'A';
                if (a == k - cnt) {
                    cout << i + 1 << " B" << endl;
                    f = 1;
                }
            }
        } else {
            int b = 0;
            int f = 0;
            for (int i = 0; !f && i < n; i++) {
                b += s[i] == 'B';
                if (b == cnt - k) {
                    cout << i + 1 << " A" << endl;
                    f = 1;
                }
            }
        }
    }

    return 0;
}
