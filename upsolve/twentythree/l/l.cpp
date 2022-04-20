#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using p = pair<int, int>;
using e = tuple<ll, int, int>;

e make_edge(p &a, p &b, int u, int v) {
    return e((a.first - b.first) * (a.first - b.first) +
            (a.second - b.second) * (a.second - b.second),
            u, v);
}

class dsu {
    private:
        vi p, rank;
    public:
        dsu(int n) {
                p.assign(n, 0); for (int i = 0; i < n; i++) p[i] = i;
                rank.assign(n, 0);
        }

        int find_set(int i) {
            return (i == p[i]) ? i : p[i] = find_set(p[i]);
        }

        bool union_set(int u, int v) {
            int i, j;
            if ((i = find_set(u)) == (j = find_set(v))) return false;

            if (rank[i] > rank[j]) swap(i, j);
            p[i] = j;
            if (rank[i] == rank[j]) rank[j]++;
            return true;
        }
};

int main() {
    int n; cin >> n;
    vector<p> v(n);
    vector<e> el;
    for (int i = 0; i < n; i++) {
        auto &[x, y] = v[i];
        cin >> x >> y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= i - 10 && j >= 0; j--) {
            el.push_back(make_edge(v[i], v[j], i, j));
        }

        for (int j = i + 1; j < n && j <= i + 10; j++) {
            el.push_back(make_edge(v[i], v[j], i, j));
        }
    }

    dsu ds(n);
    sort(el.begin(), el.end());
    int cost = 0;
    for (auto &[w, u, v] : el)
        if (ds.union_set(u, v)) cost += w;

    cout << cost << endl;
    return 0;
}

