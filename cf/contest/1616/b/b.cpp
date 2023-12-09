#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int i = 0;
        string test = "";
        do { test += s[i]; } while (i < n - 1 && (s[i] >= s[i + 1] && ++i));
        while (i >= 0) test += s[i--];
        cout << min(string() + s[0] + s[0], test) << endl;
    }
    return 0;
}
