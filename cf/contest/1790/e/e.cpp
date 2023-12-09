#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        unsigned x; cin >> x;

        unsigned a = 2 * x - x / 2, b = x / 2;
        if ((a ^ b) == x) {
            cout << a << " " << b << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
