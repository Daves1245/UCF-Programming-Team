/*
 * Author: medbar
 * Date: 2021-09-06
 */

#include <climits>
#include <set>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <stdint.h>
#include <numeric>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int constexpr N = 100000;
int constexpr M = 2 * 100000;

#define UNVISITED 0
#define VISITED 1
#define EXPLORED 2

vector<vii> adjlist(M + 10);
vi dfs_num(N + 10, UNVISITED);
vi p(N + 1);
vi dfs_parent(N + 1);

int start = 1;

void print_path(int u) {
    if (u == start) {
        printf("%d ", u);
        return;
    }
    print_path(dfs_parent[u]);
    printf("%d ", u);
}

void print_cycle(int u, int depth) {
    printf("%d\n", depth + 2);
    print_path(u);
    printf("%d ", start);
    printf("\n");
}

int dfs(int u, int depth) {
    int tmp = -1;
    dfs_num[u] = EXPLORED;
    for (int j = 0; j < (int) adjlist[u].size(); j++) {
        ii v = adjlist[u][j];
        if (dfs_num[v.first] == UNVISITED) {
            dfs_parent[v.first] = u;
            tmp = dfs(v.first, depth + 1);
        } else if (dfs_num[v.first] == EXPLORED) {
            if (v.first == dfs_parent[u]) {
                //printf("Two ways (%d, %d)-(%d, %d)\n", u, v.first, v.first, u);
            } else {
                print_cycle(v.first, depth + 2);
            }
        }
    }
    dfs_num[u] = VISITED;
    return tmp;
}

// traverse the graph, categorize the edge properties
void graphCheck(int u) {
    dfs_num[u] = EXPLORED;
    for (int j = 0; j < (int) adjlist[u].size(); j++) {
        ii v = adjlist[u][j];
        if (dfs_num[v.first] == UNVISITED) {
            dfs_parent[v.first] = u;
            graphCheck(v.first);
        } else if (dfs_num[v.first] == EXPLORED) {
            if (v.first == dfs_parent[u]) {
                printf("Two ways (%d, %d)-(%d, %d)\n", u, v.first, v.first, u);
            } else { // GOAL: grab a cycle (of length > 2)!!
                printf("Back edge (%d, %d) (Cycle)\n", u, v.first);
            }
        }
    }
    dfs_num[u] = VISITED;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(ii(v, UNVISITED));
        adjlist[v].push_back(ii(u, UNVISITED));
    }

    dfs_num.assign(n, UNVISITED);
    p.assign(N, 0);

    int cc = 0;
    for (int i = 1; i <= n; i++) {
        start = i;
        if (dfs_num[i] == UNVISITED) {
            if (dfs(i, 0)) {
                return 0;
            }
        }
        /*
        if (dfs_num[i] == UNVISITED) {
            printf("Component %d:\n", ++cc), graphCheck(i);
        }
        */
    }

    printf("IMPOSSIBLE\n");
    return 0;
}

