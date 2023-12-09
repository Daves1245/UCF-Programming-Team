#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b;
        ll c, d;
        cin >> a >> b >> c >> d;
        int x = min(b, d);
        b -= x;
        d -= x;
        if (b > 9) {
            cout << ">" << endl;
        } else if (d > 9) {
            cout << "<" << endl;
        } else {
            a *= pow(10, b);
            c *= pow(10, d);
            if (a > c) {
                cout << ">" << endl;
            } else if (a < c) {
                cout << "<" << endl;
            } else {
                cout << "=" << endl;
            }
        }
    }
    return 0;
}
