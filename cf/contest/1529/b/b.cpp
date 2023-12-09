#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        sort(v.begin(), v.end());
        int cnt = 0;
        int ecnt = 0;
        int zcnt = 0;
        for (int j = 0; j < n; j++) {
            // cout << i << " ";
            int i = v[j];
            if (i < 0) cnt++;
            else if (!i) {
                zcnt++;
            } else if ((zcnt < 2) && (!ecnt)) {
                bool f = 1;
                for (int i = 0; i < j - 1; i++) {
                    f &= abs(v[i] - v[i + 1]) >= v[j];
                }
                ecnt += f;
                break;
            }
        }

        //cout << endl;

        cout << cnt + zcnt + ecnt << endl;
    }
    return 0;
}
