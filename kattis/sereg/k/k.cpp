#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool good = true;
    for (int i = 0; good && i < n; i++) {
        int b = 0, w = 0;
        int bc = 0, wc = 0;
        for (int j = 0; j < n && good; j++) {
            if (grid[i][j] == 'B') {
                b++;
                bc++;
                wc = 0;
                if (bc >= 3) {
                    good = false;
                }
            } else {
                w++;
                wc++;
                bc = 0;
                if (wc >= 3) {
                    good = false;
                }
            }
        }
        if (!good) break;
        good = b == w;
        if (!good) break;
        b = 0, w = 0;
        bc = 0, wc = 0;
        for (int j = 0; j < n && good; j++) {
            if (grid[j][i] == 'B') {
                b++;
                bc++;
                wc = 0;
                if (bc >= 3) {
                    good = false;
                }
            } else {
                w++;
                wc++;
                bc = 0;
                if (wc >= 3) {
                    good = false;
                }
            }
        }
        if (!good) break;
        good = b == w;
        if (!good) break;
    }
    cout << good << endl;
    return 0;
}

