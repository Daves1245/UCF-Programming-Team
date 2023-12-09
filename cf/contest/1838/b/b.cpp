#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;

        int o = find(v.begin(), v.end(), 1) - v.begin(), t = find(v.begin(), v.end(), 2) - v.begin(), m = find(v.begin(), v.end(), n) - v.begin();

        if ((o < m && m < t) || (t < m && m < o)) {
            cout << "1 1" << endl;
            continue;
        }

        if ((o < t && t < m) || (m < t && t < o)) {
            cout << t + 1 << " " << m + 1 << endl;
            continue;
        }

        if ((t < o && o < m) || (m < o && o < t)) {
            cout << endl;
            continue;
        }
    }

    return 0;
}
