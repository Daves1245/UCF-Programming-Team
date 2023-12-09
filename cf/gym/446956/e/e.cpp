#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, int> freq;
        vector<int> v(n); for (auto &i : v) cin >> i, freq[i]++;
        sort(v.begin(), v.end());
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (freq[v[i] - 1] <= 0) cnt++;
            freq[v[i] - 1]--;
        }

        cout << cnt << endl;
    }

    return 0;
}
