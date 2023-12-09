#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        unordered_map<int, int> freq;
        for (auto &i : v) {
            while (i > n) i /= 2;
            freq[i]++;
        }
        for (int i = 0; i < n; i++) {
            int x = v[i];
            while (x > 1 && freq[x] > 1) {
                freq[x]--;
                x /= 2;
                freq[x]++;
            }
        }

        bool f = 1;
        for (auto [k, v] : freq) {
            f &= v == 1;
        }

        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
