#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int, int> find_pair(int d) {
    for (int x = 0; x <= 32; x++) {
        for (int y = 0; y <= 32; y++) {
            if (d == (1 << x) - (1 << y)) return {x, y};
        }
    }
    return {-1, -1};
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool f = 1;
        unordered_map<int, int> freq;
        vector<int> v(n); for (auto &i : v) cin >> i;
        ll mean = accumulate(v.begin(), v.end(), 0LL);
        f &= !(mean % n);
        mean /= n;
        for (auto &i : v) {
            i -= mean;
            auto [x, y] = find_pair(i);
            f &= (x >= 0) && (y >= 0);
            freq[x]--;
            freq[y]++;
        }

        for (auto [k, v] : freq) f &= !v;

        cout << (f ? "Yes" : "No") << endl;
    }
    return 0;
}
