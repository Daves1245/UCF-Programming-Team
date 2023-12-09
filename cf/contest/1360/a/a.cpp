#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >>  b;
        int c = min({max({a + b, a, b}), max({2 * a, b}), max({2 * b, a})});
        cout << c * c << endl;
    }
    return 0;
}
