#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; getline(cin, s);
        cin >> s;
        string t = "";
        for (int i = 1; i <= 8; i++) {
            t = s[0] + to_string(i);
            if (t == s) continue;
            else cout << t << endl;
        }
        for (int i = 0; i < 8; i++) {
            t = "";
            t += (char)(i + 'a');
            t += s[1];
            if (t == s) continue;
            else cout << t << endl;
        }
    }

    return 0;
}
