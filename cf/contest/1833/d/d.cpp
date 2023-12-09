#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int r = v.find(n) - v.begin() - 1;
        if (r == -1) {
            r = v.find(n - 1) - v.begin() - 1;
        }
        int l = r - 1;
        while (l && r + l < n) {

            l--;
        }
    }

    return 0;
}
