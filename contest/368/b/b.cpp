/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), p(n + 10), q(m);
    set<int> s;
    cin >> v[0];
    s.insert(v[0]);
    p[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> v[i - 1];
        s.insert(v[i - 1]);
        p[i] = s.size();
    }

    for (int i = 0; i < m; i++) {
        cin >> q[i];
    }

    for (int i = 1; i < m; i++) {
        cout << p[q[i]] - p[q[i - 1]] << '\n';
    }

    return 0;
}

