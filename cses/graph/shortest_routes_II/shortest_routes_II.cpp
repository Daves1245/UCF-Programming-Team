/*
 * Author: medbar
 * Date: 2021-09-09
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

#define INF 1000000000
int constexpr N = 100000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vii> adjlist(N + 10);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back(ii(v, w));
        adjlist[v].push_back(ii(u, w));
    }

    vi dist(N + 1, INF);
    dist[1] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(ii(0, 1));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < (int) adjlist[u].size(); j++) {
            ii v = adjlist[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}

