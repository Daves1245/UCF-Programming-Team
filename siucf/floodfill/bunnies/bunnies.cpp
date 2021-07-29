/*
 * Author: medbar
 * Date: 2021-07-27
 */

#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <queue>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>

using namespace std;

struct custom_hash {
    // http://xorshift.di.unimi.it/splitmix64.c
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef unordered_map<long long, int, custom_hash> safe_map;

int fast_gcd(int a, int b) {
    if (!a || !b) {
        return a | b;
    }
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) {
            swap(a, b);
        }
        b -= a;
    } while (b);
    return a << shift;
}

int lcm(int a, int b) {
    return a / fast_gcd(a, b) * b;
}

int extended_gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

bool visited[11][11];
char board[11][11];

bool floodfill(int i, int j, int r, int c) {
    if (i < 0 || i >= r || j < 0 || j >= c) return false;
    if (visited[i][j]) return false;

    visited[i][j] = true;

    if (board[i][j] == 'C') return true;
    if (board[i][j] == '#') return false;

    return floodfill(i - 1, j, r, c)
        || floodfill(i + 1, j, r, c)
        || floodfill(i, j - 1, r, c)
        || floodfill(i, j + 1, r, c);
}

/*
bool _floodfill(vector<vector<pair<char, bool>>> board, int x, int y, int row, int col) {
    board[y][x].second = true;
//    cout << "visited " << y << " " << x << ": " << board[y][x].first << ", " << board[y][x].second << endl;
    if (board[y][x].first == 'C') {
        return true;
    }
    if (x - 1 >= 0 && board[y][x - 1].first != '#' && !board[y][x - 1].second) {
        if (floodfill(board, x - 1, y, row, col)) return true;
    }
    if (x + 1 < col && board[y][x + 1].first != '#' && !board[y][x + 1].second) {
        if (floodfill(board, x + 1, y, row, col)) return true;
    }
    if (y - 1 >= 0 && board[y - 1][x].first != '#' && !board[y - 1][x].second) {
        if (floodfill(board, x, y - 1, row, col)) return true;
    }
    if (y + 1 < row && board[y + 1][x].first != '#' && !board[y + 1][x].second) {
        if (floodfill(board, x, y + 1, row, col)) return true;
    }
    return false;
}
*/

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int row, col;
        scanf("%d %d\n", &row, &col);
        ii start;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] = getchar();
                if (board[i][j] == 'P') {
                    start = ii(i, j);
                }
            }
            getchar();
        }
        /*
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
        */
        printf("%s\n", floodfill(start.first, start.second, row, col) ? "yes" : "no");
        memset(visited, 0, sizeof visited);
    }
    return 0;
}

