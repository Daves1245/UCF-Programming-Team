#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        int n = str.size();
        pair<int, int> f = {0, 0}, s = {0, 0};
        int ans = 10;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                s.first += str[i] == '1';
                s.second += str[i] == '?';
            } else {
                f.first += str[i] == '1';
                f.second += str[i] == '?';
            }

            if (f.first + f.second > s.first + (10 - i) / 2) {
                ans = i + 1;
                break;
            }
            if (s.first + s.second > f.first + (9 - i) / 2) {
                ans = i + 1;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
