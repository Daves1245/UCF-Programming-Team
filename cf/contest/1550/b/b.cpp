#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        if (b >= 0) {
            cout << (a + b) * n << endl;
        } else {
            int c = unique(s.begin(), s.end()) - s.begin();
            cout << a * n + (c / 2 + 1) * b << endl;
        }
    }
    return 0;
}
