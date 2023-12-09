#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        int bcnt = s[n - 1] == 'B';
        for (int i = n - 2; i >= 0; i--) {
            bcnt += s[i] == 'B';
            if ((s[i] == 'A') && (s[i + 1] == 'B')) {
                cnt += bcnt;
                bcnt = 1;
                swap(s[i], s[i + 1]);
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
