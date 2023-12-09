#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            i++;
            while (i < n && s[i] != c) {
                i++;
            }
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
