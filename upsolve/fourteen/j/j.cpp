/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vp = vector<pair<double, double>>;

double area(vp &p, int start, int len) {
    double ret = 0;
    for (int i = 0; i <= len; i++) {
        int a = start + (start + i) % len;
        int b = start + (start + i + 1) % len;
        auto [x1, y1] = p[a];
        auto [x2, y2] = p[b];
        ret += x1 * y2 - x2 * y1;
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vp verts(n);
        for (int i = n - 1; i >= 0; i--) {
            cin >> verts[i].first >> verts[i].second;
        }

        double ans = 0;
        // /*
        for (int i = 0; i < n; i++) {
            double a = area(verts, 0, n);
            for (int j = i + 1; j < n; j++) {
                double b = area(verts, i, j - i);
                if (min(b, a - b) != 0)
                    ans = max(ans, min(b, a - b));
            }
        }
        // */

        // cout << "the area of the entire polygon is " << area(verts, 0, verts.size()) / 2 << endl;

        cout << (int) round(ans) << endl;
    }
    return 0;
}

