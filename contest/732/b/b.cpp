#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int ans = 0, prev = k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (prev + v[i] < k) {
            int next = k - prev - v[i];
            ans += next;
            v[i] += next;
        }
        prev = v[i];
    }
    cout << ans << endl;
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

