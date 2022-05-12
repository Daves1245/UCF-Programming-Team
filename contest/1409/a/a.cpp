#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        int d = abs(a - b);
        cout << (d / 10) + (d % 10 ? 1 : 0) << endl;
    }
    return 0;
}

