#include <bits/stdc++.h>

using namespace std;

int toggle(vector<bool> &on, int n) {
    int ret = 0;
    if (n == 0) {
        for (int i = 0; i < 4; i++) {
            ret += on[i];
            on[i] = false;
        }
        return ret;
    }

    for (int i = n; i < 4; i++) {
        ret += on[i];
        on[i] = false;
    }

    if (!on[n - 1]) {
        on[n - 1] = true;
        ret++;
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int c = 0;
        vector<bool> on(4, false);
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            c += toggle(on, tmp);
        }

        cout << c << endl;
    }
    return 0;
}

