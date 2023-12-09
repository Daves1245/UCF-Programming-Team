#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s = "";
        if (n < 10) {
            cout << n << endl;
            continue;
        } else if (n > 45) {
            cout << -1 << endl;
            continue;
        } else if (n == 45) {
            cout << "123456789" << endl;
            continue;
        }
        int d = 9;
        while (n >= d) {
            n -= d;
            s += to_string(d);
            d--;
        }
        if (n) s += to_string(n);
        sort(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}
