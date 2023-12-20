#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int f = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i + 1] == '0') continue;
            int a = stoi(s.substr(0, i + 1)), b = stoi(s.substr(i + 1));
            if (b > a) {
                cout << a << " " << b << endl;
                f = 1;
                break;
            }
        }
        if (!f) cout << -1 << endl;
    }

    return 0;
}
