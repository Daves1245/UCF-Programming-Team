/*
 * Author: medbar
 * Date: 2021-09-07
 */

#include <climits>
#include <set>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N = 100000;
int M = 2 * 100000;

class UnionFind {
    public:
        vi p;
        vi size;
        vi rank;
        int distincts;
        int max_size = 1;

        UnionFind(int n) {
            p.resize(n + 1);
            size.resize(n + 1);
            rank.resize(n + 1);
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

        void union_set(int i, int j) {
            int pi = find_set(i), pj = find_set(j);
            if (pi == pj) return;

            size[pi] = size[pj] = size[pi] + size[pj];

            distincts--;
            if (rank[pi] > rank[pj]) {
                p[pj] = pi;
            } else {
                p[pi] = pj;
                if (rank[pi] == rank[pj]) {
                    rank[pj]++;
                }
            }
            max_size = max(max_size, max(size[pi], size[pj]));
        }
};


int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        uf.union_set(a, b);
        cout << uf.distincts << " " << uf.max_size << endl;
    }

    return 0;
}

