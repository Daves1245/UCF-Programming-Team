#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    int cnt = 0;
    while (m > n) {
        m = (m % 2) ? m + 1 : m / 2;
        cnt++;
    }
    while (m < n) {
        m++;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
