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
    string a;
    getline(cin, a);
    while (t--) {
        getline(cin, a);
        int c = a[a.size() - 1] - '0';
        if (c % 2 == 0) {
            cout << 0 << endl;
            continue;
        }
        c = a[0] - '0';
        if (c % 2 == 0) {
            cout << 1 << endl;
            continue;
        }
        bool f = false;
        for (int i = 1; i < a.size(); i++) {
            c = a[i] - '0';
            if (c % 2 == 0) {
                f = true;
            }
        }
        if (f) {
            cout << 2 << endl;
            continue;
        }
        cout << -1 << endl;
        continue;
    }
    return 0;
}

