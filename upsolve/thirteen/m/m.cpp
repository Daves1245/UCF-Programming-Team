/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

using umbra = tuple<long, long, long>;
using ll = long long;

int within(int a, int b, umbra &u) {
    auto &[x, y, r] = u;
    return llabs((ll) pow(a - x, 3)) + llabs((ll) pow(b - y, 3)) <= r;
}

ll points(int a, int b, int c, int d, vector<umbra> &v) {
    // cout << "a " << a << " b " << b << " c " << c << " d " << d << endl;

    auto iumbras = [&](int a, int b, int c, int d, vector<umbra> v) -> int {
        int intersections = 0;
        for (auto &i : v) {
            intersections += within(a, b, i) + within(c, d, i);
        }

        return intersections;
    };

    int interiors = iumbras(a, b, c, d, v);
    if (a == c && b == d) {
        return interiors > 0;
    }

    //cout << "interiors " << interiors << endl;
    if (interiors == 0) {
        return (c - a) * (d - b);
    }

    if (interiors < 2) {
        int e = (a + c) / 2, f = (b + d) / 2;
        return points(a, b, e, f, v)
            + points(e + 1, b, c, f, v)
            + points(a, f + 1, e, d, v)
            + points(e + 1, f + 1, c, d, v);
    }

    return 0;
}

int main() {
    int n, k; cin >> n >> k;
    vector<umbra> v(n);
    for (auto &[x, y, r] : v) {
        cin >> x >> y >> r;
    }

    cout << points(0, 0, n, n, v) << endl;
    return 0;
}

