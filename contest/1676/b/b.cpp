#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int m = INT_MAX;
        for (int i = 0; i < n; i++) {
            m = min(m, v[i]);
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += v[i] - m;
        }

        cout << s << endl;
    }
    return 0;
}

