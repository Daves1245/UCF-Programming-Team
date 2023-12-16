#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        cout << "? 1" << endl;
        int q1; cin >> q1;
        cout << "? 2" << endl;
        int q2; cin >> q2;

        if (2 * b == 3 * a) {
            // what
        }

        if (q2 == q1) {
            cout << "! " << 2 * (q2 - 1) << " AC" << endl;
        }

        if (q2 == 2 * q1 - 1) {
            cout << "! " << 2 * (q1 - 1) + 1 << " AD" << endl;
        }

        if (q2 == q1 + 1) {
            cout << "! " << 2 * q1 << " BC" << endl;
        }

        if (q2 == 2 * q1 + 1) {
            cout << "! " << 2 * q1 + 1 << " BD" << endl;
        }
    }

    return 0;
}
