#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int oc = 0, tc = 0;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                oc++;
            } else {
                tc++;
            }
        }

        if (oc % 2 == 0 && !(oc == 0 && tc % 2 == 1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

