#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, q; cin >> n >> a >> q;
        string s; cin >> s;
        bool possible = a >= n;
        bool guaranteed = a >= n;
        int pcnt = 0, acpy = a;
        for (auto c : s) {
            if (c == '+') a++, pcnt++;
            else a--;
            possible |= acpy + pcnt >= n;
            guaranteed |= a >= n;
        }

        if (guaranteed) {
            cout << "YES" << endl;
        } else if (!possible) {
            cout << "NO" << endl;
        } else {
            cout << "MAYBE" << endl;
        }
    }
}
