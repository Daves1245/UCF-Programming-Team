#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> t;
        vector<int> a(n); for (auto &i : a) cin >> i;
        vector<int> b(n); for (auto &i : b) cin >> i, t.insert(i);
        bool o = is_sorted(a.begin(), a.end());
        cout << (((t.size() > 1) || o) ? "Yes" : "No") << endl;
    }
    return 0;
}
