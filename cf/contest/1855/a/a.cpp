#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;

        int c = 0;
        for (int i = 0; i < n; i++) {
            c += v[i] == i + 1;
        }

        cout << (c / 2) + (c % 2) << endl;
    }

    return 0;
}
