#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i : a) cin >> i;
    vector<int> b(n); for (auto &i : b) cin >> i;
    vector<int> f(n + 1, 0);
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) m[b[i]] = i;
    for (int i = 0; i < n; i++) f[(i - m[a[i]] + n) % n]++;
    // for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << endl;

    cout << *max_element(f.begin(), f.end()) << endl;
    return 0;
}
