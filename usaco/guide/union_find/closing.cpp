#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> vi;

class uf_ds {
    public:
        vi p;
        vi rank;
        vi size;
        vector<bool> _open;
        int parent;
        int num_open;

        uf_ds(int n) {
            p.resize(n + 1); _open.resize(n + 1); rank.resize(n + 1), size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                rank[i] = 0;
                size[i] = 1;
                p[i] = i;
                _open[i] = false;
            }
            num_open = 0;
        }
        int find_set(int i) {
            return (p[i] == i) ? i : (p[i] = find_set(p[i]));
        }

        bool same_set(int i, int j) {
            return find_set(i) == find_set(j);
        }

        void open(int i) {
            _open[i] = true;
            num_open++;
        }

        bool isopen(int i) {
            return _open[i];
        }

        void union_set(int i, int j) {
            int pi = find_set(i), pj = find_set(j);
            if (pi == pj) return;
            size[pi] = size[pj] = size[pi] + size[pj];
            if (rank[pi] > rank[pj]) {
                p[pj] = pi;
            } else {
                p[pi] = pj;
                if (rank[pi] == rank[pj]) {
                    rank[pj]++;
                }
            }
        }

        void set_parent(int i) {
            parent = i;
        }

        bool connected() {
            return num_open == size[find_set(parent)];
        }
};

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define UNVISITED 0

int main() {

    ifstream in("closing.in");
    ofstream out("closing.out");

    int n, m;
    in >> n >> m;
    vector<vii> adjlist(n + 1);
    stack<int> st;
    stack<bool> ans;
    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        adjlist[u].push_back(ii(v, UNVISITED));
        adjlist[v].push_back(ii(u, UNVISITED));
    }
    vi perm(n);
    for (int i = 0; i < n; i++) {
        int t;
        in >> t;
        st.push(t);
    }

    uf_ds ufds(n);
    ufds.set_parent(st.top());
    ufds.open(st.top());
    st.pop();
    bool prev;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        prev = ufds.connected();
        ufds.open(u);

        for (int j = 0; j < (int) adjlist[u].size(); j++) {
            ii v = adjlist[u][j];
            if (ufds.isopen(v.first)) {
                ufds.union_set(u, v.first);
            }
        }
        bool cur = ufds.connected();

        printf("opened %d\n", u);
        for (int i = 1; i <= n; i++) {
            printf("\t%d: open = %d\n", i, true == ufds._open[i]);
        }
        printf("Currently %d farms are open and size[parent] is %d\n",
                    ufds.num_open, ufds.size[ufds.parent]);
        cout << "connected: " << ufds.connected() << endl;
        printf("prev: %d, cur: %d\n", prev, cur);
        cout << "output: " << (prev) << endl;
        if (prev) {
            ans.push(true);
        }
        if (!prev &)
    }
    /*
    if (ufds.connected()) {
        out << "YES" << endl;
    } else {
        out << "NO" << endl;
    }
    */
    ans.push(prev);
    while (!ans.empty()) {
        out << ((ans.top()) ? "YES" : "NO") << endl;
        ans.pop();
    }
    return 0;
}
