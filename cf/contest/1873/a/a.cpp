#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        bool f = s == "abc";
        swap(s[0], s[1]);
        f |= s == "abc";
        swap(s[0], s[1]);
        swap(s[1], s[2]);
        f |= s == "abc";
        swap(s[1], s[2]);
        swap(s[0], s[2]);
        f |= s == "abc";

        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
