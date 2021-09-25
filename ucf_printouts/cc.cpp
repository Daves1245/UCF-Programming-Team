// connected components
int main() {
    int cc = 0;
    dfs_num.assign(V, UNVISITED);
    for (int i = 0; i < V; i++) {
        if (dfs_num[i] == UNVISITED) {
            printf("CC %d: ", ++cc), dfs(i), printf("\n");
        }
    }
}
