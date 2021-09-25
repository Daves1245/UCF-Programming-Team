#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class union_find {
    public:
        vi p;
        vi rank;
        vi size;
        int distincts;

        union_find(int n) {
            p.resize(n);
            for (int i = 0; i < n; i++) p[i] = i;
            rank.assign(n, 0);
            size.assign(n, 1);
            distincts = n;
        }

        int find_set(int i) {
            return (p[i] == i) ? i : p[i] = find_set(p[i]);
        }

        bool same_set(int i, int j) {
            return find_set(i) == find_set(j);
        }

        void union_set(int i, int j) {
            int x = find_set(i), y = find_set(j);
            if (x == y) return;
            size[x] = size[y] = size[x] + size[y];
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
            distincts--;
        }

        int height(int i) {
            int ret = 0;
            while (p[i] != i) {
                i = p[i];
                ret++;
            }
            
            return ret;
        }
};

#define btoa(x) ((x) ? "yes" : "no")

int main() {
    const int N = 10e5;
    union_find ds(N);

    int q = 0, u, v;
    while (q != -1) {
        cin >> q >> u >> v;
        switch (q) {
            case 0:
                ds.union_set(u, v);
                break;
            case 1:
                cout << btoa(ds.same_set(u, v)) << endl;
                break;
            case 2:
                printf("u: %d, v: %d\n", ds.height(u), ds.height(v));
            default:
                break;
        }
    }

    return 0;
}
