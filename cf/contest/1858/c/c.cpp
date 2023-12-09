#include <bits/stdc++.h>
using namespace std;
using vll = vector<long long>;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll v;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * i <= n; j *= 2) {
                if (!s.count(i * j)) {
                    v.push_back(i * j);
                    s.insert(i * j);
                }
            }
        }

        for (auto i : v) cout << i << " "; cout << endl;
    }
    return 0;
}
