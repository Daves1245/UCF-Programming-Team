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

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

#define INF INT_MAX
int constexpr N = 100000;
int constexpr M = 2 * 100000;

vi color(N + 10, INF);
queue<int> q;
vector<vii> adjlist(M + 10);

bool bipartite(int u) {
    color[u] = 0;
    q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < (int) adjlist[u].size(); i++) {
            ii v = adjlist[u][i];
            if (color[v.first] == INF) {
                color[v.first] = 1 - color[u];
                q.push(v.first);
            }
            if (color[v.first] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(ii(b, INF));
        adjlist[b].push_back(ii(a, INF));
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == INF) {
            if (!bipartite(i)) {
                printf("IMPOSSIBLE\n");
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", color[i] + 1);
    }
    printf("\n");

    return 0;
}

