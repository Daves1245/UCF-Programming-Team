#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        vector<int> s;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        s = v;
        sort(s.begin(), s.end());
        for (auto i : v) {
            cout << n - (lower_bound(s.begin(), s.end(), i) - s.begin() + cnt[i]) << " ";
            cnt[i]++;
        }
        cout << endl;
    }
    return 0;
}
