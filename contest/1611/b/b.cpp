/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << min((a + b) / 4, a, b) << endl;
    }
    return 0;
}

