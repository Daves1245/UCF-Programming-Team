#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n; vector<int> v(n);
    int ma = INT_MIN, mai = -1;
    int mi = INT_MAX, mii = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > ma) {
            ma = v[i];
            mai = i;
        } if (v[i] <= mi) {
            mi = v[i];
            mii = i;
        }
    }

    if (mii > mai) {
        cout << mai + n - mii - 1 << endl;
    } else {
        cout << mai + n - mii - 2 << endl;
    }
    return 0;
}

