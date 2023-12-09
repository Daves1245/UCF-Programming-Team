#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i++) {
            a += (s[i] == 'a') && (s[i + 1] == 'b');
            b += (s[i] == 'b') && (s[i + 1] == 'a');
        }

        if (a < b) {
            cout << "a" + s.substr(1) << endl;
        } else if (a > b) {
            cout << "b" + s.substr(1, s.size() - 1) << endl;
        } else {
            cout << s << endl;
        }
    }
    return 0;
}
