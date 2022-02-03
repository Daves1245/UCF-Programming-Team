#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef long double ld;

typedef pair<ld, ld> vec;
typedef pair<vec, vec> line;

#define xx first
#define yy second

vec operator-(const vec& a, const vec& b) { return vec(a.xx - b.xx, a.yy - b.yy); }
vec operator+(const vec& a, const vec& b) { return vec(a.xx + b.xx, a.yy + b.yy); }
vec operator*(double c, const vec& v) { return vec(c * v.xx, c * v.yy); }

#define UNVISITED 0
#define VISITED 1

void bfs(vector<bool> &visited, vector<vii> &adjlist, int s) {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto &[v, w] : adjlist[u]) {
            if (!visited[v]) {
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, n;
        cin >> d >> n;
        cout << d << " ";

        vector<vii> adjlist_red(n);
        vector<vii> adjlist_green(n);
        for (int i = 0; i < n; i++) {
            int u;
            cin >> u;
            adjlist_red[u].push_back(ii(i, UNVISITED));
        }

        for (int i = 0; i < n; i++) {
            int u;
            cin >> u;
            adjlist_green[u].push_back(ii(i, UNVISITED));
        }

        queue<int> redq;
        queue<int> greenq;
        for (int i = 0; i < (int) adjlist_red.size(); i++) {
            if (adjlist_red[i].size() > 1) {
                redq.push(i);
            }
        }

        for (int i = 0; i < (int) adjlist_green.size(); i++) {
            if (adjlist_green[i].size() > 1) {
                greenq.push(i);
            }
        }

        bool possible = false;
        while (!redq.empty()) {
            vector<bool> visited(n, false);
            int u = redq.front(); redq.pop();
            bfs(visited, adjlist_red, u);
            bool f = true;
            for (int i = 0; i < n; i++) {
                f &= visited[i];
            }
            if (!f) {
                possible = true;
                break;
            }
        }

        while (!greenq.empty()) {
            vector<bool> visited(n, false);
            int u = greenq.front(); greenq.pop();
            bfs(visited, adjlist_green, u);
            bool f = true;
            for (int i = 0; i < n; i++) {
                f &= visited[i];
            }
            if (!f) {
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
