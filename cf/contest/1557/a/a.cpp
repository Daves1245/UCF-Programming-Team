#include <bits/stdc++.h>
using namespace std;
using ld = long double;
int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        long long s = accumulate(v.begin(), v.end(), (long long) 0);
        long long m = *max_element(v.begin(), v.end());
        cout << fixed << setprecision(9) << 
            m + ((ld) s - m) / (n - 1) << endl;
    }
    return 0;
}
