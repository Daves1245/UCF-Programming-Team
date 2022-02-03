#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef struct {
    long long x, y, r;
    long long num, den;
    int parity;
} circle;

bool inbounds(const circle &a, const circle &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.x - b.x) + (a.y - b.y) <= (a.r + b.r) * (a.r + b.r);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vii> adjlist(n);
        
        vector<circle> circles(n);
        for (int i = 0; i < n; i++) {
            cin >> circles[i].x circles[i].y circles[i].r;
        }

        for (int i = 0; i < circles.size(); i++) {
            for (int j = 0; j < circles.size(); j++) {
                if (i == j) continue;
                if (inbounds(circles[i], circles[j])) {
                    adjlist[i].push_back(ii(j, UNVISITED));
                    adjlist[j].push_back(ii(i, UNVISITED));
                }
            }
        }
        
        queue<int> q;
        q.push(0);
        int p = 0;
        vector<bool> visited(n, false);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (visited[u]) continue;
            for (auto &[v, w] : adjlist[u]) {
                if (!visited[v]) {
                    circles[v].parity = p;
                }
            }
        }
    }
    return 0;
}

