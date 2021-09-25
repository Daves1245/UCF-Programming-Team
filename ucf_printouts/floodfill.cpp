// floodfill
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int floodfill(int r, int c, char c1, char c2) { // returns the size of CC
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; // outside grid
    if (grid[r][c] != c1) return 0; // does not have color c1
    int ans = 1; // adds 1 to ans because vertex (r, c has color c1
    grid[r][c] = c2; // now recolors veretex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 8; d++) {
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    }
    return ans;
}
