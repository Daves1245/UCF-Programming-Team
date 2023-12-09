#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        for (auto i : v) cout << n - i + 1 << " ";
        cout << endl;
    }

    return 0;
}
