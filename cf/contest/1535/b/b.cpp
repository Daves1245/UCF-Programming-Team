#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int e = 0;
        vector<int> o;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            e += !(v[i] % 2);
            if (v[i] % 2) o.push_back(v[i]);
        }
        int a = o.size();
        int ans = (e - 1) * e / 2 + e * a; 
        sort(o.begin(), o.end());
        for (int i = 0; i < a; i++) {
            for (int j = i + 1; j < a; j++) {
                ans += gcd(o[i], o[j]) > 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
