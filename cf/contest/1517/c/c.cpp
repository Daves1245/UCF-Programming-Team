#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n); for (auto &i : v) cin >> i;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        int x = i, y = i;
        for (int j = 1; j <= v[i]; j++) {
            grid[x][y] = v[i];
            if ((y > 0) && (grid[x][y - 1] == -1)) y--;
            else x++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    return 0;
}
