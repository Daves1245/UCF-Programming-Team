// dfs.cpp
#define UNVISITED 0
#define VISITED 1

vi dfs_num(N + 10, UNVISITED);
vector<vii> adjlist(N + 10);

void dfs(int u) {
    dfs_num[u] = VISITED;
    for (int j = 0; j < adjlist[u].size(); j++) {
        ii v = adjlist[u][j];
        if (dfs_num[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
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
    // dfs(start);
    return 0;
}
