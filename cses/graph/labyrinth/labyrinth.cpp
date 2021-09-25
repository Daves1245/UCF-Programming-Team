/*
 * Author: medbar
 * Date: 2021-08-29
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

ii grid[1010][1010];
bool visited[1001][1001] = {false};
char answer[1000 * 1000 + 10] = {0};
queue<ii> tovisit;

void print_visited(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar((visited[i][j]) ? '1' : '0');
        }
        putchar('\n');
    }
}

bool bfs(int r, int c) {
    while (!tovisit.empty()) {
        ii cur = tovisit.front();
        tovisit.pop();

        if (visited[cur.first][cur.second]) continue;
        //printf("size of queue is %ld\n", tovisit.size());
        visited[cur.first][cur.second] = true;
        if (grid[cur.first][cur.second].first == '#') continue;

        //printf("visited %d, %d\n", cur.first, cur.second);
        //print_visited(r, c);

        if (grid[cur.first][cur.second].first == 'B') {
            int i = cur.first, j = cur.second, k = 0;
            do {
                char cur_char = grid[i][j].second;
                answer[k] = cur_char;
                k++;
                //answer[k++] = grid[i][j].second;
                switch (grid[i][j].second) {
                    case 'U':
                        i++;
                        break;
                    case 'D':
                        i--;
                        break;
                    case 'L':
                        j++;
                        break;
                    case 'R':
                        j--;
                        break;
                    default:
                        break;
                }
            } while (grid[i][j].first != 'A');
            return true;
        }

        if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second]) {
            tovisit.push(ii(cur.first - 1, cur.second));
//            printf("visited[%d][%d] = %d\n", cur.first - 1, cur.second, visited[cur.first - 1][cur.second]);
            grid[cur.first - 1][cur.second].second = 'U';
        }
        if (cur.first + 1 < r && !visited[cur.first + 1][cur.second]) {
            tovisit.push(ii(cur.first + 1, cur.second));
//            printf("visited[%d][%d] = %d\n", cur.first + 1, cur.second, visited[cur.first + 1][cur.second]);
            grid[cur.first + 1][cur.second].second = 'D';
        }
        if (cur.second - 1 >= 0 && !visited[cur.first][cur.second - 1]) {
            tovisit.push(ii(cur.first, cur.second - 1));
//            printf("visited[%d][%d] = %d\n", cur.first, cur.second - 1, visited[cur.first][cur.second - 1]);
            grid[cur.first][cur.second - 1].second = 'L';
        }
        if (cur.second + 1 < c && !visited[cur.first][cur.second + 1]) {
            tovisit.push(ii(cur.first, cur.second + 1));
//            printf("visited[%d][%d] = %d\n", cur.first, cur.second + 1, visited[cur.first][cur.second + 1]);
            grid[cur.first][cur.second + 1].second = 'R';
        }
    }
    return false;
}

void print_grid(int rows, int cols, char grid[1010][1010]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    memset(grid, -1, sizeof grid);
    ii start;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++ /* kek */) {
            grid[r][c].first = getchar();
            grid[r][c].second = '\0';
            if (grid[r][c].first == 'A') {
                start.first = r;
                start.second = c;
                tovisit.push(start);
            }
        }
        getchar(); // ignore newline
    }
    if (bfs(n, m)) {
        puts("YES");
        printf("%ld\n", strlen(answer));
        for (int i = strlen(answer) - 1; i >= 0; i--) {
            putchar(answer[i]);
        }
        putchar('\n');
    } else {
        puts("NO");
    }
    return 0;
}

