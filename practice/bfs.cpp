#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000
#define btoa(x) ((x) ? "YES" : "NO")
#define UNVISITED 0
#define VISITED 1

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int N = 100000;

vector<vii> adjlist(N + 10);
vi d(N + 10, INF);
vi p(N + 10, 0);

void print_path(int u, int s) {
    if (u == s) {
        printf("%d ", u);
        return;
    }
    print_path(p[u], s);
    printf("%d ", u);
}

bool bfs(int s, int e) {
    queue<int> pq; pq.push(s);
    d[s] = 0;
    while (!pq.empty()) {
        int u = pq.front(); pq.pop();
        for (int i = 0; i < (int) adjlist[u].size(); i++) {
            ii v = adjlist[u][i];
            if (d[v.first] == INF) {
                d[v.first] = d[u] + 1;
                p[v.first] = u;
                pq.push(v.first);
            }
            if (v.first == e) {
                printf("steps taken: %d\n", d[v.first]);
                printf("path taken: ");
                print_path(v.first, s);
                printf("\n");
                return true;
            }
        }
    }
    return false;
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

    printf("start, end: ");
    int s, e;
    cin >> s >> e;

    printf("%s\n", btoa(bfs(s, e)));
    return 0;
}
