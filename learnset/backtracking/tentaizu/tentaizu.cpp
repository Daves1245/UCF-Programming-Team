#include <bits/stdc++.h>

using namespace std;

vector<string> board(7);
vector<string> orig(7);

bool inbounds(int i, int j) {
    return (i >= 0 && i < 7 && j >= 0 && j < 7);
}

bool place(int y, int x) {
    bool flag = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int u = y + i, v = x + j;
            if (!inbounds(u, v) || (i == 0 && j == 0)) continue;
            if (board[u][v] == '0') {
                flag = false;
            }
            if (board[u][v] != '0' && isdigit(board[u][v])) {
                board[u][v]--;
            }
        }
    }
    return flag;
}

void unplace(int y, int x) {
    for (int i = -1; i < 2; i++) {
        for (int j = 1; j < 2; j++) {
            int u = y + i, v = x + j;
            if (!inbounds(u, v) || (i == 0 && j == 0)) continue;
            if (isdigit(board[u][v])) board[u][v]++;
        }
    }
}

bool bt(int y, int x) {
    if (y >= 7) return true;
    if (x >= 7) return bt(y + 1, 0);
    // cout << y << " " << x << endl;
    if (!isdigit(board[y][x]) || board[y][x] == '0') return bt(y, x + 1);

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int u = y + i, v = x + j;
            if (!inbounds(u, v) || i == 0 && j == 0 || board[u][v] != '.') continue;
            board[u][v] = '*';
            if (place(u, v) && bt(y, x + 1)) {
                // cout << "true" << endl;
                return true;
            }
            unplace(u, v);
            board[u][v] = '.';
        }
    }

    return false;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 7; i++) {
            cin >> board[i];
            orig[i] = board[i];
        }

        bt(0, 0);

        cout << "Tentaizu Board #" << t << ":\n";
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (isdigit(orig[i][j])) {
                    cout << orig[i][j];
                    // cout << board[i][j];
                } else {
                    cout << board[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

