#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        if (s == "?") {
            cout << "B" << endl; continue;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '?') {
                if (s[i - 1] == 'R') s[i] = 'B';
                else s[i] = 'R';
            }
        }
        cout << s << endl;
    }
    return 0;
}
