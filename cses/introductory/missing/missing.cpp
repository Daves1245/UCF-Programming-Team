/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res ^= i;
    }
    int net = 0;
    for (int i = 0; i < n - 1; i++) {
        int tmp; cin >> tmp;
        net ^= tmp;
    }

    cout << (res ^ net) << endl;
    return 0;
}

