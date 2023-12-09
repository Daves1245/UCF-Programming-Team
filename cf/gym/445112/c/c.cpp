#include <bits/stdc++.h>
using namespace std;
bool prime(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
}
int main() {
    int t; cin >> t;
cases: while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> f(10, 0);
        for (auto c : s) {
            f[c - '0']++;
            if (!prime(c)) {
                cout << 1 << endl;
                cout << c << endl;
                t--;
                goto cases;
            }
        }

        string ret = "";
        for (auto c : s) {
            if (f[c - '0'] > 1) {
                f[c - '0']--;
            } else {
                ret += c;
            }
        }
        cout << ret.size() << endl;
        cout << ret << endl;
    }

    return 0;
}
