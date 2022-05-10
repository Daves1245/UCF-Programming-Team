#include <bits/stdc++.h>

using namespace std;

int diff(string a, string b) {
    int ret = 0;
    for (int i = 0; i < a.size(); i++) {
        ret += abs(a[i] - b[i]);
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, r; cin >> n >> r;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int m = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                m = min(m, diff(v[i], v[j]));
            }
        }

        cout << m << endl;
    }
    return 0;
}

