#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int d = max(a, b) - min(a, b);
        int r = d / (2 * c);
        if (d % (2 * c)) r++;
        cout << r << endl;
    }
    return 0;
}
