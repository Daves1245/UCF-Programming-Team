#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        unordered_map<int, int> freq;
        for (auto &i : v) cin >> i;
        sort(v.begin(), v.end());
        for (auto i : v) freq[i]++;
        bool good = v[0] == 0;
        v.resize(unique(v.begin(), v.end()) - v.begin());
        for (int i = 1; i < v.size(); i++) {
            good &= freq[v[i]] <= freq[v[i] - 1] & (v[i] == v[i - 1] + 1);
        }

        cout << (good ? "YES" : "NO") << endl;
    }

    return 0;
}
