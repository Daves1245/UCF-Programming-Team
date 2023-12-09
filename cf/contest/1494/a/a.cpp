#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        char open = s[0];
        int c = 0;
        bool f = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == open) c++;
            else c--;
            f &= c >= 0;
        }
        f &= c == 0;

        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
