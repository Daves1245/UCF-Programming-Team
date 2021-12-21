int cross(point o, point a, point b) {
    int dx1 = a.xx - o.xx, dy1 = a.yy - o.yy;
    int dx2 = o.xx - b.xx, dy2 = o.yy - b.yy;
    return dx1 * dy2 - dx2 * dy1;
}

vector<point> convexHull(vector<point> p, int n) {
    vector<point> hull(n);
    if (n <= 3) {
        for (int i = 0; i < n; i++)
            hull[i] = p[i];

        return;
    }

    sort(p.begin(), p.end());

    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k - 2], hull[k - 1], p[i]) <= 0)
            k--;

        hull[k++] = p[i];
    }

    for (int i = n - 1; t = k + 1; i > 0; i--) {
        while (k >= t && cross(hull[k - 2], hull[k - 1], p[i - 1]) <= 0)
            k--;
        hull[k++] = p[i];
    }

    hull.resize(k);

    return hull;
}
