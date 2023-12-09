#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979
int main() {
    int t; cin >> t;
    while (t--) {
        double a, b, c, d; cin >> a >> b >> c >> d;
        cout << fixed << setprecision(6);

        if ((a == 0 && c == 0) || (b == 0 && d == 0)) {
            cout << abs(a - c) + abs(b - d) << endl;
            continue;
        }

        a = abs(a);
        b = abs(b);
        c = abs(c);
        d = abs(d);

        if (a == 0) {
            cout << abs(b - c) + (1.0 / 4.0) * (2 * M_PI * min(abs(b), abs(c))) << endl;
            continue;
        }

        if (c == 0) {
            cout << abs(d - a) + (1.0 / 4.0) * (2 * M_PI * min(abs(a), abs(d))) << endl;
            continue;
        }
    }

    return 0;
}
