#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<int> freq(4, 0);
        bool good = true;
        bool flag = false;
        if (v.size() == 2) good = (v[1] - v[0]) <= 3;
        if (v.size() == 1) goto end;
        /*
        if (v.size() == 3) {
            if (v[1] - v[0] <= 2 && v[2] - v[1] <= 2) goto end;
        }
        for (int i = 1; good && i < n - 1; i++) {
            int diff = v[i + 1] - v[i];
            if (diff > 2) {
                good = false;
            }
            if (flag && diff == 2) {
                good = false;
            }
            if (diff == 2) flag = true;
        }

        */
        for (int i = 1; good && i < n - 1; i++) {
            int diff = v[i + 1] - v[i];
            if (diff > 2 && v.size() != 3) {
                good = false;
                goto end;
            }
            if (i != n - 2 || diff != 2)
                freq[diff]++;
        }

        if (v.size() == 3) {
            good = (freq[3] < 2 && freq[2] == 0) || (freq[2] <= 2) || freq[2] <= 2;
            goto end;
        }

        good = freq[2] < 2;
end:
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

