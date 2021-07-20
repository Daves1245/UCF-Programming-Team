/*
 * Author: medbar
 * Date: 2021-07-13
 */

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
#include <bits/stdc++.h>

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

void print(ii p) {
    printf("[%d, %d]", p.first, p.second);
}

void printfirst(ii p) {
    if (p.first == 'S' || p.first == 'F') {
        printf("%c", p.first);
    } else {
        printf("%d", p.first);
    }
}

void print_visited(vector<vii> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            //print(board[i][j]);
            printfirst(board[i][j]);
        }
        printf("\n");
    }
}

bool _path(vector<vii> board, int x, int y, int N, int choice) {
    printf("Traversing at x = %d, y = %d, choice = %d!\n", x, y, choice);
    if ((x + 1 <= N && board[x + 1][y].first == 'F') || (y + 1 <= N && board[x][y + 1].first == 'F')) {
        return true;
    }
    if (x - 1 >= 0 && !board[x - 1][y].second && board[x - 1][y].first == choice) {
        board[x - 1][y].second = 1;
        printf("(%d,%d) SET: %d\n", x - 1, y, board[x - 1][y].second);
        return _path(board, x - 1, y, N, choice);
    }
    if (x + 1 <= N && !board[x + 1][y].second && board[x + 1][y].first == choice) {
        board[x + 1][y].second = 1;
        printf("(%d,%d) SET: %d\n", x + 1, y, board[x + 1][y].second) ;
        return _path(board, x + 1, y, N, choice);
    }
    if (y - 1 >= 0 && !board[x][y - 1].second && board[x][y - 1].first == choice) {
        board[x][y - 1].second = 1;
        printf("(%d,%d) SET: %d\n", x, y - 1,board[x][y - 1].second);
        return _path(board, x, y - 1, N, choice);
    }
    if (y + 1 <= N && !board[x][y + 1].second && board[x][y + 1].first == choice) {
        board[x][y + 1].second = 1;
        printf("(%d,%d) SET: %d\n", x, y + 1, board[x][y + 1].second);
        return _path(board, x, y + 1, N, choice);
    }
    printf("(%d, %d): Trapped!\n", x, y);
    return false;
}

bool haspath(vector<vii> board, int N) {
    return _path(board, 0, 0, N, 1) || _path(board, 0, 0, N, 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vii> board(n);
        int N = n - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = getchar();
                while (tmp == '\n') {
                    tmp = getchar();
                }
                if (tmp != 'S' && tmp != 'F') {
                    tmp -= '0';
                }
                board[i].push_back(pair<int, int>(tmp, 0));
            }
        }
        printf("Test case #%d: %d\n", t + 1, (int) haspath(board, N));
    }
    return 0;
}

