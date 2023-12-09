#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n + 1);
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> v[i + 1];
        }
        for (int i = 0; i <= n; i++) s.insert(i);
        for (auto i : v) s.erase(i);
        int mex = *s.begin();
        k %= (n + 1);
        v[0] = mex;
        swap(v[0], v[1]);
        for (int i = 0; i < n; i++) {
            cout << v[(i + k) % (n + 1)] << " ";
        }
        cout << endl;
    }
    return 0;
}
