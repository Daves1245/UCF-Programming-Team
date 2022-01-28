/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int a, b, c;
bool valid(int d) {
    return ((a + d) % b == 0) && ((b + d) % b == 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int e = abs(c - a) / 2, f = abs(b - a), g = abs(c - b);
        if (valid(e) || valid(f) || valid(g)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

