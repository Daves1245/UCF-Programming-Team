// union find disjoint set
class ufds {
    public:
        vi p;
        vi rank;
        vi size;
        int num_distincts;
        ufds(int n) {
            p.resize(n); rank.resize(n); size.resize(n);
            for (int i = 0; i < n; i++) {
                rank[i] = 0;
                size[i] = 1;
                p[i] = i;
            }
            distincts = n;
        }
        int find_set(int i) {
            return (p[i] == i) ? i : (p[i] = find_set(p[i]));
        }
        bool same_set(int i, int j) {
            return find_set(i) == find_set(j);
        }
        void union_set(int i, int j) {
            int pi = find_set(i), pj = find_set(j);
            if (pi == pj) return;
            distincts--;
            size[pi] = size[pj] = size[pi] + size[pj];
            if (rank[pi] > rank[pj]) {
                p[pj] = pi;
            } else {
                p[pi] = p[pj];
                if (rank[pi] == rank[pj]) {
                    rank[pj]++;
                }
            }
        }
};
