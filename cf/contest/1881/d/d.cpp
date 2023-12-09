#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<bool> pr(1e4, 1);
    vector<int> primes;
    pr[0] = pr[1] = 0;
    for (int i = 2; i < pr.size(); i++)
        if (pr[i]) {
            primes.push_back(i);
            for (int j = i + i; j < pr.size(); j += i)
                pr[j] = 0;
        }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        unordered_map<int, int> f;
        for (auto i : v) {
            for (int d : primes) {
                if (d * d > i) break;
                while (!(i % d)) {
                    f[d]++;
                    i /= d;
                }
            }
            if (i > 1) f[i]++;
        }

        int b = 1;
        for (auto [k, v] : f) b &= !(v % n);

        cout << (b ? "YES" : "NO") << endl;
    }
    return 0;
}
