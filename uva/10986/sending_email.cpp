/*
 * Author: medbar
 * Date: 2021-09-08
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int N = 999, M = 999;

int grid[N + 10][M + 10];

class ufds {
    public:
        vi p;
        vi size;
        vi rank;
        int distincts;

        ufds(int n) {
            p.resize(n); size.resize(n); rank.resize(n);
            for (int i = 0; i < n; i++) {
                rank[i] = 0;
                size[i] = 1;
                p[i] = i;
            }
            distincts = n;
        }

        bool same_set(int i, int j) {
            return find_set(i) == find_set(j);
        }

        void union_set(int i, int j) {
            int pi = find_set(i), pj = find_set(j);
            if (pi == pj) return;
            distincts--;
            if (rank[pi] > rank[pj]) {
                p[pj] = pi;
            } else {
                p[pi] = pj;
                if (rank[pi] == rank[pj]) {
                    rank[pj]++;
                }
            }
        }
};

void dijkstra(int n, int m) {
    priority_queue<pair<int, ii>> pq; pq.push(0, ii(0, 0));
    while (!pq.empty()) {
        auto v = pq.front(); pq.pop();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cout << dijkstra(n, m) << endl;
    }
    return 0;
}

