#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int o = count(s.begin(), s.end(), '1'), z = count(s.begin(), s.end(), '0');
        int f = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (!o) {
                    cout << z << endl;
                    f = 1;
                    break;
                } else o--;
            }
            if (s[i] == '1') {
                if (!z) {
                    cout << o << endl;
                    f = 1;
                    break;
                } else z--;
            }
        }
        if (!f) cout << 0 << endl;
    }

    return 0;
}
