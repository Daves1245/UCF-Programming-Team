#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        int a = -1, b = -1;
        for (int i = 0; i < n - 1; i++) {
            if (((s[i] == 'a') && (s[i + 1] == 'b'))
                   || ((s[i] == 'b') && (s[i + 1] == 'a'))) {
                a = i + 1;
                b = i + 2;
            }
        }

        cout << a << " " << b << endl;
    }

    return 0;
}
