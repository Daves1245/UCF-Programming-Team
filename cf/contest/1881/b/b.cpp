#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        vector<int> v(3); for (auto &i : v) cin >> i;
        sort(v.begin(), v.end());
        int a = v[0], b = v[1], c = v[2];
        int d = gcd(a, b);
        d = gcd(d, c);
        a /= d;
        b /= d;
        c /= d;

        if (a == 1) {
            if ((a == b) && (b == c)) {
                cout << "YES" << endl;
                continue;
            }
            if ((a == b) && (c <= 4)) {
                cout << "YES" << endl;
                continue;
            }
            if ((b == 2) && (c <= 3)) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}
