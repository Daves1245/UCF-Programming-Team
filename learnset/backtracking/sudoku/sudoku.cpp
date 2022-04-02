#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));

bool check(int y, int x) {
    for (int i = 0; i < 9; i++) {
        if (i != x)
            if (board[y][i] != 0 && board[y][i] == board[y][x]) return false;
        if (i != y)
            if (board[i][x] != 0 && board[i][x] == board[y][x]) return false;
    }

    y /= 3;
    x /= 3;
    /*
    cout << x << " " << y << endl;
    cout << endl;
    */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int u = 3 * x + i, v = 3 * y + j;
            // cout << u << " " << v << endl;
            if (u == y && v == x) continue;
            if (board[u][v] != 0 && board[u][v] == board[y][x]) return false;
        }
    }

    /*
       for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
       unordered_set<int> s;
       for (int k = 0; k < 3; k++) {
       for (int l = 0; l < 3; l++) {
       int u = 3 * i + k, v = 3 * j + l;
       if (board[u][v] != 0 && s.count(board[u][v]) > 0) return false;
       s.insert(board[u][v]);
       }
       }
       }
       }
       */

    return true;
}

void printb() {
    for (auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << '\n';
    }
}

bool backtrack(int i, int j) {
    /*
       cout << i << " " << j << endl;
       printb();
       */
    if (j >= 9) i++, j = 0;
    if (i >= 9) return true;
    if (board[i][j] != 0) return backtrack(i, j + 1);

    int tmp = board[i][j];
    for (int c = 1; c <= 9; c++) {
        board[i][j] = c;
        if (check(i, j) && backtrack(i, j + 1)) {
            return true;
        }
    }
    board[i][j] = tmp;

    return false;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        board = vector<vector<int>>(9, vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }

        // printb();

        cout << "Test case " << t << ":\n";
        if (backtrack(0, 0)) {
            printb();
        } else {
            cout << "No solution possible.\n";
        }

        if (t != T)
            cout << '\n';

    }
    return 0;
}

