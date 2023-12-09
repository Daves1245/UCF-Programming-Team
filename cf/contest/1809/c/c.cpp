#include <bits/stdc++.h>
using namespace std;
void dp(vector<int> &v, int n, int k) {
    if (k <= 0 || n <= 0) return;
    if (k >= n) {
        v[n - 1] = 1000;
        dp(v, n - 1, k - n);
    } else {
        v[k - 1] = 50;
        v[k] = -100;
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n, -1);
        dp(v, n, k);
        for (auto i : v) cout << i << " "; cout << endl;
    }
    return 0;
}
