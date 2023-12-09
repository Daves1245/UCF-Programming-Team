#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int d;
        if (b < c) {
            d = c - b;
            if (((b - d) % a) == 0) {
                cout << "test" << endl;
            }
        }
    }
    return 0;
}
