#include <iostream>
#include <vector>
#include <algorithm>

#define UNVISITED 0
#define VISITED 1

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int N = 100000;

vector<vii> adjlist(N + 10);
vi dfs_num(N + 10);

void dfs(int u) {
    dfs_num[u] = VISITED;
    for (int i = 0; i < (int) adjlist[u].size(); i++) {
        ii v = adjlist[u][i];
        if (dfs_num[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    dfs_num.assign(n, UNVISITED);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(ii(v, UNVISITED));
        adjlist[v].push_back(ii(u, UNVISITED));
    }

    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == UNVISITED) {
            cc++;
            dfs(i);
        }
    }
    printf("Connected components: %d\n", cc);
    return 0;
}
