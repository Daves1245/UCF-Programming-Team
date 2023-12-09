#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int ibest = -1;
        auto fz = s.find('0');
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] + s[i + 1] - 2 * '0' >= 10) {
                ibest = i;
                break;
            }
        }

        if (ibest != -1) {
            cout << s.substr(0, ibest) << s[ibest] + s[ibest + 1] - 2 * '0' << s.substr(ibest + 2) << endl;
        } else {
            cout << s[0] + s[1] - 2 * '0' << s.substr(2) << endl;
        }
    }
    return 0;
}
