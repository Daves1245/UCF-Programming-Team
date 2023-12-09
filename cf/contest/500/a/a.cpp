#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t; cin >> n >> t;
    vector<int> v(n + 1); for (int i = 1; i <= n - 1; i++) cin >> v[i];
    int i = 1;
    vector<int> seen(n + 1, 0);
    while (!seen[i] && (i <= n)) {
        seen[i] = true;
        i = i + v[i];
    }
    cout << (seen[t] ? "YES" : "NO") << endl;
    return 0;
}
