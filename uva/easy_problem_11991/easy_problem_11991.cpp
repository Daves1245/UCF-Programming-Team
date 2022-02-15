/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        unordered_map<int, vector<int>> adj;
        for (int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            adj[tmp].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            int k, v; cin >> k >> v;
            if (adj.count(v) && adj[v].size() >= k) {
                cout << adj[v][k - 1] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}

