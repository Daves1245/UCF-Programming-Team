/*
 * Author: medbar
 * Date: 2021-08-29
 */

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
#include <cstring>

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

char grid[1010][1010];

void print_grid(int rows, int cols, char grid[1010][1010]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}

bool visited[1010][1010];

void print_visited(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar((visited[i][j]) ? '1' : '0');
        }
        putchar('\n');
    }
}

bool _floodfill(int i, int j, int r, int c, bool (*func)(int, int, int, int)) {
    if (i < 0 || i >= r || j < 0 || j >= c || visited[i][j]) return false;

    visited[i][j] = true;

    if (!func(i, j, r, c)) return false;

    return _floodfill(i - 1, j, r, c, func)
        || _floodfill(i + 1, j, r, c, func)
        || _floodfill(i, j - 1, r, c, func)
        || _floodfill(i, j + 1, r, c, func);
}

queue<ii> tovisit;

bool floodfill(int x, int y, int r, int c, bool (*func)(int i, int j, int r, int c)) {
    bool ret = _floodfill(x, y, r, c, func);
    memset(visited, false, sizeof(visited));
    return ret;
}

bool floodfill_no_reset(int x, int y, int r, int c, bool (*func)(int i, int j, int r, int c)) {
    return _floodfill(x, y, r, c, func);
}

bool populate_room(int i, int j, int r, int c) {
    return grid[i][j] == '.';
}

int find_rooms(int r, int c) {
    int ret = 0;
    memset(visited, false, sizeof(visited));
    while (!tovisit.empty()) {
        ii cur = tovisit.front();
        tovisit.pop();
        if (!visited[cur.first][cur.second]) {
            ret++;
            floodfill_no_reset(cur.first, cur.second, r, c, populate_room);
        }
    }
    //print_visited(r, c);
    return ret;
}

void solve(int rows, int cols, char grid[1010][1010]) {
    cout << find_rooms(rows, cols) << endl;
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    memset(grid, -1, sizeof grid);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++ /* lol */) {
            grid[r][c] = getchar();
            if (grid[r][c] == '.') {
                tovisit.push(ii(r, c));
            }
        }
        getchar(); // ignore newline
    }
    //print_grid(n, m, grid);
    solve(n, m, grid);
    return 0;
}

