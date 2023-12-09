#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string a, b; cin >> a >> b;
        int i = 0;
        for (int j = 0; a.size() <= n * m; j++) {
            if (a.find(b) != string::npos) break;
            a += a;
            i++;
        }

        cout << (a.find(b) != string::npos ? i : -1) << endl;
    }
    return 0;
}
