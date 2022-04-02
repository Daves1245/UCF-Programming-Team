/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        if (a == 0) {
            cout << 1 << endl;
        } else {
            cout << a + 2 * b + 1 << endl;
        }
    }
    return 0;
}

