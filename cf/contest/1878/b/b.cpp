#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                cout << 3 * i << " ";
            } else {
                cout << 3 * i + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
