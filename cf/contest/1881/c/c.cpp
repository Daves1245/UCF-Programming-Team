#include <bits/stdc++.h>
using namespace std;
using vi = vector<char>;
using vvi = vector<vi>;
/*
vvi rotate(vvi &v) {
    int n = v.size();
    vvi ret = v;
    for (int i = 0; i < n / 2; i++) {
        int f = i;
        int l = n - 1 - i;
        for (int i = f; i < l; i++) {
            int off = i - f;
            int top = ret[f][i];
            ret[f][i] = ret[l - off][f];
            ret[l - off][f] = ret[l][l - off];
            ret[l][l - off] = ret[i][l];
            ret[i][l] = top;
        }
    }
    return ret;
}
*/

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> v(n); for (auto &i : v) cin >> i;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char mx = v[i][j];
                int a, b;
                a = i, b = j;
                for (int k = 0; k < 4; k++) {
                    mx = max(mx, v[a][b]);
                    int c = a;
                    a = n - 1 - b;
                    b = c;
                }
                a = i, b = j;
                for (int k = 0; k < 4; k++) {
                    cnt += abs(v[a][b] - mx);
                    v[a][b] = mx;
                    int c = a;
                    a = n - 1 - b;
                    b = c;
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}

