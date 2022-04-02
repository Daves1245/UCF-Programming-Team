#include <bits/stdc++.h>

using namespace std;

using vec = pair<long double, long double>;

#define x first
#define y second

vec operator+(const vec & v, const vec & u) { return {v.x+u.x, v.y+u.y}; }
vec operator-(const vec & v, const vec & u) { return {v.x-u.x, v.y-u.y}; }
vec operator *(const vec & v, const long double & c) { return {v.x * c, v.y * c}; }

long double dotProd(vec v, vec u) { return v.x*u.x + v.y*u.y; }
long double crossProd(vec v, vec u) { return v.x*u.y - v.y*u.x; }

int main() {
    vec a, b, c, d, e, f;
    while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y >> e.x >> e.y >> f.x >> f.y && !(a.x == 0 && a.y == 0 && b.x == 0 && b.y == 0 && c.x == 0 && c.y == 0 && d.x == 0 && d.y == 0 && e.x == 0 && e.y == 0)) {

        long double area = fabs(crossProd(e - d, f - d)) / 2;
        long double lo = 0, hi = 1000000, t;
        vec h;
        for (int i = 0; i < 200; i++) {
            t = (lo + hi) / 2;
            h = ((c - a) * t);
            long double candidate = fabs(crossProd(h, b - a));
            if (candidate > area) {
                hi = t;
            } else {
                lo = t;
            }
        }

        h = h + a;
        vec g = b + h - a;
        cout << setprecision(3) << fixed << g.x << " " << g.y << " " << h.x << " " << h.y << endl;
    }

    return 0;
}

