#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int aw = 0, bw = 0;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                int acnt = 0, bcnt = 0;
                int asw = 0, bsw = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] == 'A') acnt++;
                    else bcnt++;
                    if (acnt >= x) {
                        acnt = 0;
                        asw++;
                        if ((i == s.size() - 1) && (asw == y)) {
                            aw++;
                        }
                    }
                    if (bcnt >= x) {
                        bcnt = 0;
                        bsw++;
                        if ((i == s.size() - 1) && (bsw == y)) {
                            bw++;
                        }
                    }
                }
            }
        }

        if (aw == bw) {
            cout << "?" << endl;
        } else if (aw > bw) {
            cout << "A" << endl;
        } else {
            cout << "B" << endl;
        }
    }

    return 0;
}
