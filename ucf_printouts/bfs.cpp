// bfs
#define INF INT_MAX

int main() {
    // ...
    vi d(N + 1, INF); d[s] = 0;
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int) adjlist[u].size(); j++) {
            ii v = adjlist[u][j];
            if (d[v.first] == INF) {
                d[v.first] = d[u] + 1;
                q.push(v.first);
            }
        }
    }
}
