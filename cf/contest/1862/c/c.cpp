#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unordered_map<int, int> freq;
        vector<int> v(n); for (auto &i : v) cin >> i, freq[i]++;
        vector<int> a(n);
        bool good = v[0] == n;
        int k = n - 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += freq[v[i]];
            good &= sum == v[k];
            i += freq[v[i]] - 1;
            k -= freq[v[k]];
        }

        cout << (good ? "YES" : "NO") << endl;
    }
    return 0;
}
