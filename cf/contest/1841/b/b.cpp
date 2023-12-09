#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int l = v[0];
        
        int prev = v[0];
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (v[i] < prev && v[i] <= v[0] && sorted) {
                sorted = false;
                prev = v[i];
                cout << "1";
                continue;
            }
            bool f = v[i] >= prev;
            if (!sorted) f &= v[i] <= v[0];
            cout << (f ? "1" : "0");
            if (f) prev = v[i];
        }
        cout << endl;
    }

    return 0;
}
