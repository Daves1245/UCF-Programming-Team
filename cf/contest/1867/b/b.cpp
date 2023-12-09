#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0, ocnt = 0;
        for (int i = 0; i < n / 2; i++) {
            cnt += s[i] != s[n - 1 - i];
            ocnt += (s[i] == '1');
        }

        for (int i = 0; i <= n; i++) {
            bool f = 1;
            f &= (i >= cnt) && (i <= n - cnt);
            if (!(n % 2)) f &= (i - cnt) % 2 == 0;
            cout << f;
        }
        cout << endl;
    }
    return 0;
}
