#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> v(m); for (int i = 0; i < m; i++) cin >> v[i];
    int mi = INT_MAX;
    sort(v.begin(), v.end());
    for (int i = 0; i < m - n + 1; i++) {
        mi = min(mi, v[i + n - 1] - v[i]);
    }
    cout << mi << endl;
    return 0;
}

