#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> order(n + 1);
        for (int i = 0; i < n; i++) {
            order[v[i]] = i + 1;
        }
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (order[i + 1] < order[i]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
