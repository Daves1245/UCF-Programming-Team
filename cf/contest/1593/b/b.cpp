#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        string keys[] = {"00", "25", "50", "75"};
        int ids[] = {1, 1, 1, 1};
        int mi = n + 10;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (ids[j] < 0) continue;
                if (s[i] == keys[j][ids[j]]) ids[j]--;
                if (ids[j] < 0) mi = min(mi, n - i - 2);
            }
        }
        cout << mi << endl;
    }
    return 0;
}
