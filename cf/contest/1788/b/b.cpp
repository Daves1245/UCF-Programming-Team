#include <bits/stdc++.h>
using namespace std;
pair<int, int> solve(int n) {
    if ((n % 10) == 9) {

    } else if (n % 2) {
        return {(n + 1) / 2, (n - 1) / 2};
    } else {
        return {n / 2, n / 2};
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        auto digs = [](int n) -> int {
            int ret = 0;
            while (n) {
                ret += n % 10;
                n /= 10;
            }
            return ret;
        };

        auto [x, y] = solve(n);
        cout << x << " " << y << endl;
    }
    return 0;
}
