/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        /*
        cout << "a " << a << " b " << b << " c " << c << endl;
        cout << "!(b 0 and c 0) " << !(b == 0 && c == 0) << endl;
        */
        int m = max(a, max(b, c));
        cout << max(max(b, c) - a + 1, 0) << " ";
        cout << max(max(a, c) - b + 1, 0) << " ";
        cout << max(max(a, b) - c + 1, 0) << " ";
        cout << '\n';
    }
    return 0;
}

