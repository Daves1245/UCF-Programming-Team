#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> v(26, 0);
        for (auto c : s) v[c - 'A']++;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            cnt += v[i] >= i + 1;
        }

        cout << cnt << endl;
    }

    return 0;
}
