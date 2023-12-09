#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k, a, b; cin >> n >> k >> a >> b;
        int ans = (n / k) * b;
        ans += min(n - ans, a);
        cout << n - ans << endl;
    }
    return 0;
}
