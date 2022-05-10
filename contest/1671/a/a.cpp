#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string a;
        cin >> a;
        int ac = 0, bc = 0;
        int last = a[0];
        bool good = a.size() > 1;
        int count = 0;
        char prev = a[0];
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == prev) count++;
            else {
                if (count == 1) {
                    good = false;
                    break;
                }
                count = 1;
                prev = a[i];
            }
        }

        good &= count != 1;

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

