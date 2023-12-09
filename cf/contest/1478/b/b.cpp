#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int q, d; cin >> q >> d;
        while (q--) {
            int x; cin >> x;
            if (x >= 10 * d) {
                cout << "YES" << endl;
                continue;
            }

            bool f = 1;
            while (f && x >= d) {
                if (x % 10 == d) {
                    cout << "YES" << endl;
                    f = 0;
                }
                x -= d;
            }
            if (f) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
