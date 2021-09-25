/*
 * Author: medbar
 * Date: 2021-09-05
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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int extended_gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

#define UNVISITED -1
#define VISITED 1

int constexpr N = 100000;

#define INF INT_MAX

vi p(N + 1);
void print_path(int u) {
    if (u == 1) {
        printf("%d ", u);
        return;
    }
    //printf("p[%d] = %d\n", p[u]);
    print_path(p[u]);
    printf("%d ", u);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vii> adjlist(m + 10);
    vi d(n + 1, INF); d[1] = 0;
    queue<int> q;
    q.push(1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(ii(b, UNVISITED));
        adjlist[b].push_back(ii(a, UNVISITED));
    }

    while (!q.empty()) {
        int c = q.front(); q.pop();

        if (c == n) {
            printf("%d\n", d[c] + 1);
            print_path(c);
            printf("\n");
            return 0;
        }

        for (int i = 0; i < (int) adjlist[c].size(); i++) {
            ii v = adjlist[c][i];
            if (d[v.first] == INF) {
                d[v.first] = d[c] + 1;
                q.push(v.first);
                p[v.first] = c;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
