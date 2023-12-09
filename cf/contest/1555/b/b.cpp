#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int W, H; cin >> W >> H;
        int a, b, c, d; cin >> a >> b >> c >> d;
        int e, f, g, h; cin >> e >> f >> g >> h;

        if (abs(a - c) + abs(e - g) > W && abs(b - d) + abs(f - h) > H) {
            cout << -1 << endl;
            continue;
        }

        cout << min({
                max(g - a, 0),
                max(e - c, 0),
                max(),
                });
    }
    return 0;
}
