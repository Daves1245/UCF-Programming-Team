#include <bits/stdc++.h>
using namespace std;
using ll = long long;
tuple<int, int, int> find_set(int d) {
    int z = -1;
    for (int x = 0; x <= 32; x++) {
        if (d == (1 << x)) z = x;
        for (int y = 0; y <= 32; y++) {
            if (d == -(1 << y)) z = y;
            if (d == (1 << x) - (1 << y)) return {x, y, z};
        }
    }
    return {-1, -1, z};
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        unordered_map<int, int> freq;
        bool f = 1;
        ll mean = accumulate(v.begin(), v.end(), 0LL);
        f &= !(mean % n);
        mean /= n;
        for (auto &i : v) {
            i -= mean;
            if (!i) continue;
            auto [x, y] = find_pair(i);
            f &= (x >= 0 || y >= 0);
            if (x != -1) freq[x]++;
            if (y != -1) freq[y]--;
        }
        ll sum = 0;
        for (auto [k, v] : freq) {
            cout << "k, v: " << k << " " << v << endl;
            sum += k * v;
        }

        cout << "sum " << sum << endl;
        f &= !sum;
        cout << (f ? "Yes" : "No") << endl;
    }
    return 0;
}
