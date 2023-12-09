#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vll = vector<ll>;
#define p(i) ((i & (i - 1)) == 0)
int msb(int n) {
    n = abs(n);
    int ret = 0;
    while (n) (n >>= 1), ret++;
    return ret;
}
pair<int, int> find_xy(int n) {
    for (int i = 0; i <= 32; i++) {
        for (int j = 0; j <= 32; j++) {
            if ((1 << i) - (1 << j) == n) return {i, j};
        }
    }
    return {-1, -1};
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll v(n); for (auto &i : v) cin >> i;
        ll sum = accumulate(v.begin(), v.end(), 0LL);
        bool f = (sum % n) == 0;
        unordered_map<int, int> freq;
        for (auto &i : v) {
            i -= sum / n;
            if (p(abs(i))) freq[msb(abs(i))]++;
        }
        for (auto i : v) {
            if (!i) continue;
            if (!p(abs(i))) {
                auto [a, b] = find_xy(i);
                if (a < 0 || b < 0) f = false;
                f &= freq[a] && freq[b];
                freq[a]--, freq[b]--;
            } else {
                freq[msb(abs(i))]++;
            }
        }

        for (int i = 1; i <= 40; i++) {
            f &= !freq[i] || (freq[i] == freq[-i]);
        }

        cout << (f ? "Yes" : "No") << endl;
    }
    return 0;
}
