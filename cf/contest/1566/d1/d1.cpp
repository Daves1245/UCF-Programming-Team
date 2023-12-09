#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> v(n * m);
        for (auto &i : v) cin >> i;
        int cnt = 0;
        for (int i = 0; i < n * m; i++) {
            for (int j = i + 1; j < n * m; j++) {
                if (v[j] > v[i]) cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
